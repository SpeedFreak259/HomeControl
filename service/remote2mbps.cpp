#include <string>
#include <getopt.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <RF24/RF24.h>
#include <unistd.h>

using namespace std;

RF24 radio(RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

const unsigned short DEFAULT_TIMEOUT = 1000;

/* Message types */
const unsigned short MSGTYPE_FULL = 0x01;
const unsigned short MSGTYPE_CMD_DIMMER = 0x02;
const unsigned short MSGTYPE_CMD_SWITCH = 0x03;
const unsigned short MSGTYPE_CMD_STATUS_REQUEST = 0x04;

const unsigned short MSGTYPE_ACK_DIMMER = 0XA2;
const unsigned short MSGTYPE_ACK_SWITCH = 0xA3;

const unsigned short MSGTYPE_NACK = 0xFF;


typedef struct{
  unsigned short messageType;
} messageType_t;

typedef struct{
  unsigned short dimmerNumber;
  unsigned short dimmerLevel;
} dimmerCommand_t;

typedef struct{
  unsigned short id;
  unsigned short state;
} switchCommand_t;

typedef struct{
  unsigned short powerSupplyVoltageRaw;
  unsigned short powerSupplyCurrentRaw;
  unsigned short internalTemperatureC00;
  unsigned short externalTemperatureC00;
  unsigned short outputSwitchState;
  unsigned short inputSwitchState;
  unsigned short dimmer1Demand;
  unsigned short dimmer2Demand;
  unsigned short dimmer1Actual;
  unsigned short dimmer2Actual;
} statusReport_t;

/* End of message types */

statusReport_t statusReport;
messageType_t ackMessage;
messageType_t incomingData;

void setup(void){
	//Prepare the radio module
	printf("\nPreparing interface\n");
	radio.begin();
	radio.setRetries( 15, 15);
	radio.setChannel(0x4c);
	radio.setPALevel(RF24_PA_MAX);
	radio.setDataRate(RF24_2MBPS);

	radio.printDetails();
	radio.openWritingPipe(pipes[0]);
	radio.openReadingPipe(1,pipes[1]);
}


void printStatus(){
    float volts = (statusReport.powerSupplyVoltageRaw/1024.0)*19.98;

    printf("Status response received.\n\r");
    printf("V      : %hu (%f volts)\r\n", statusReport.powerSupplyVoltageRaw, volts);
    printf("I      : %hu \r\n", statusReport.powerSupplyCurrentRaw);
    printf("T int  : %hu \r\n", statusReport.internalTemperatureC00);
    printf("T ext  : %hu \r\n", statusReport.externalTemperatureC00);
    printf("Output : %hu \r\n", statusReport.outputSwitchState);
    printf("Input  : %hu \r\n", statusReport.inputSwitchState);
    printf("Dim1[D]: %hu \r\n", statusReport.dimmer1Demand);
    printf("Dim1[A]: %hu \r\n", statusReport.dimmer1Actual);
    printf("Dim2[D]: %hu \r\n", statusReport.dimmer2Demand);
    printf("Dim2[A]: %hu \r\n", statusReport.dimmer2Actual);
}


bool waitForData(unsigned short timeoutMs)
{
  radio.startListening();
  unsigned long started_waiting_at = millis();
  bool timeout = false;
  while ( ! radio.available() && ! timeout ) {
    if (millis() - started_waiting_at > timeoutMs ){
      timeout = true;
    }
  }

  if(timeout){
    printf("Timeout \r\n");
    return false;
  }

  return true;
}


void clearAck(){
  ackMessage.messageType = MSGTYPE_NACK;
}

void readIncoming() {
	radio.read(&incomingData, sizeof(messageType_t));
        switch(incomingData.messageType){
		case MSGTYPE_FULL:
		   radio.read(&statusReport, sizeof(statusReport_t));
                   printStatus();
                   break;

                default:
                  printf("Unrecognised request");

	}
}

bool waitForAck(unsigned short expectedMessageType) {
  clearAck();
  if(!waitForData(DEFAULT_TIMEOUT)){
    return false;
  }

  radio.read(&ackMessage, sizeof(messageType_t));

  if(ackMessage.messageType == expectedMessageType){
	return true;
  } else {
    printf("Unexpected Ack %hu, expected %hu \r\n", ackMessage.messageType, expectedMessageType);
  }

  return false;
}


void readStatus()
{
  if(waitForData(DEFAULT_TIMEOUT)){
    radio.read(&statusReport, sizeof(statusReport_t) );
    printStatus();
  }
}


void sendHeader(unsigned short header){
    printf("Sending Header : %hu \r\n", header);
    messageType_t messageType;

    messageType.messageType = header;

    radio.stopListening();
    radio.write(&messageType, sizeof(messageType_t));
}


bool setSwitch(unsigned short switchNumber, unsigned short state){
  switchCommand_t switchCommand;

  sendHeader(MSGTYPE_CMD_SWITCH);

  switchCommand.id = switchNumber;
  switchCommand.state = state;

  radio.write(&switchCommand, sizeof(switchCommand));

  if(!waitForAck(MSGTYPE_ACK_SWITCH)){
   printf("Switch command not acknowledged\r\n");
   return false;
  }

  return true;
}


bool setDimmer(unsigned short dimmerNumber, unsigned short dimmerLevel){
  dimmerCommand_t dimmerCommand;

  dimmerCommand.dimmerNumber = dimmerNumber;
  dimmerCommand.dimmerLevel = dimmerLevel;

  sendHeader(MSGTYPE_CMD_DIMMER);
  radio.write(&dimmerCommand, sizeof(dimmerCommand_t));


  if(!waitForAck(MSGTYPE_ACK_DIMMER)){
   printf("Dimmer command not acknowledged\r\n");
   return false;
  }

  return true;
}


bool requestStatus(){
	sendHeader(MSGTYPE_CMD_STATUS_REQUEST);

        if(!waitForAck(MSGTYPE_FULL)){
	  printf("No response to status request\r\n");
	  return false;
        }

	readStatus();
        return true;
}

int main( int argc, char ** argv){

	setup();

	printf("\n Automation Conductor\n");

	while(1==1){
                radio.startListening();

		printf("1. Request Status \r\n");
        	printf("2. Dimmer 1 Full\r\n");
        	printf("3. Dimmer 1 Half\r\n");
        	printf("4. Dimmer 1 Zero\r\n");
        	printf("A|a Switch 1 On/Off \r\n");
        	printf("B|b Switch 2 On/Off \r\n");
        	printf("C|c Switch 3 On/Off \r\n");
        	printf("D|d Switch 4 On/Off \r\n");

        	printf("\r\n9. Quit\r\n");

		char c = getchar();

		switch(c){
	  		case '1':
				if(!requestStatus()){
                                  printf("Status request failed\r\n");
                                }

				break;

			case '2':
				setDimmer(0, 255);
				setDimmer(1, 255);
				break;

			case '3':
				setDimmer(0, 127);
				setDimmer(1, 127);
				break;

			case '4':
				setDimmer(0, 0);
				setDimmer(1, 0);
				break;

			case 'a':
				setSwitch(0, 0);
				break;

                        case 'b':
                                setSwitch(1, 0);
                                break;

                        case 'c':
                                setSwitch(2, 0);
                                break;

                        case 'd':
                                setSwitch(3, 0);
                                break;

                        case 'A':
                                setSwitch(0, 1);
                                break;

                        case 'B':
                                setSwitch(1, 1);
                                break;

                        case 'C':
                                setSwitch(2, 1);
                                break;

                        case 'D':
                                setSwitch(3, 1);
                                break;


	  		case '9':
				return 1;

			default:
				if(radio.available()){
					readIncoming();
				}
		}
	}
}
