#include <Wire.h>
#include <avr/pgmspace.h>

const char dimmerPwmMap[] PROGMEM = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                                    ,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2
                                    ,2,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,9,9,9,9
                                    ,9,10,10,10,10,11,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,18,18,19,19,19,20
                                    ,20,21,21,22,22,23,23,24,25,25,26,26,27,28,28,29,29,30,31,32,32,33,34,35,35,36,37,38,39,40,40,41
                                    ,42,43,44,45,46,47,48,50,51,52,53,54,55,57,58,59,61,62,63,65,66,68,69,71,72,74,76,77,79,81,83,85
                                    ,86,88,90,92,94,97,99,101,103,105,108,110,113,115,118,120,123,126,129,131,134,137,140,143,147,150
                                    ,153,157,160,164,167,171,175,179,183,187,191,195,199,204,208,213,218,222,227,232,237,243,248,255};

/*

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */
 /*
  Hack.lenotta.com
  Modified code of Getting Started RF24 Library
  It will switch a relay on if receive a message with text 1, 
  turn it off otherwise.
  Edo
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define STATUS_UPDATE_INTERVAL_MS 10000

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

#define A_VOLTAGE_PIN A5
#define A_CURRENT_PIN A1

#define D_SWITCH1_PIN 3
#define D_SWITCH2_PIN 4
#define D_SWITCH3_PIN 7
#define D_SWITCH4_PIN 8

#define PWM_1_PIN 5
#define PWM_2_PIN 6

unsigned long lastStatus = millis();

/* PWM State */
typedef struct{
  int pin;
  int current;
  int demand;
} dimmerControl_t;

dimmerControl_t dimmers[2]; 

/* Output state */
typedef struct{
  int pin;
  unsigned short state;
  unsigned short value;
} switchControl_t;
switchControl_t switchOutputs[4];

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


//
// Hardware conf
//

// Set up nRF24L01 radio on SPI bus plus pins 9 & 10 

RF24 radio(9,10);

const unsigned short DEFAULT_TIMEOUT_MS = 1000;


// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

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

statusReport_t statusReport;

void setup(void)
{
  //
  // Print preamble
  //
  Serial.begin(57600);

  printf_begin();
  printf("\nAutomation Controller\n\r");

  //
  // Setup and configure rf radio
  //
  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement

  radio.begin();
  //radio.setAutoAck(1);                    // Ensure autoACK is enabled
  radio.setRetries(15,15);
  radio.setDataRate(RF24_2MBPS);
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
  radio.printDetails();

  setDigitalOuts();
  setPwmOuts();  
  setAnalog();
  // dumpDimmerMap();
}

void setAnalog() {
  analogReference(EXTERNAL);
  analogRead(A0);
}

void setPwmOuts() {
  pinMode(PWM_1_PIN, OUTPUT);
  pinMode(PWM_2_PIN, OUTPUT);

  analogWrite(PWM_1_PIN, 0);
  analogWrite(PWM_2_PIN, 0);

  dimmers[0].pin = PWM_1_PIN;
  dimmers[1].pin = PWM_2_PIN;
}

void setDigitalOuts()
{
  pinMode(D_SWITCH1_PIN, OUTPUT);
  pinMode(D_SWITCH2_PIN, OUTPUT);
  pinMode(D_SWITCH3_PIN, OUTPUT);
  pinMode(D_SWITCH4_PIN, OUTPUT);

  digitalWrite(D_SWITCH1_PIN, HIGH);
  digitalWrite(D_SWITCH2_PIN, HIGH);
  digitalWrite(D_SWITCH3_PIN, HIGH);
  digitalWrite(D_SWITCH4_PIN, HIGH);

  switchOutputs[0].pin = D_SWITCH1_PIN;
  switchOutputs[1].pin = D_SWITCH2_PIN;
  switchOutputs[2].pin = D_SWITCH3_PIN;
  switchOutputs[3].pin = D_SWITCH4_PIN;

  switchOutputs[0].value = 0x01;
  switchOutputs[1].value = 0x02;
  switchOutputs[2].value = 0x04;
  switchOutputs[3].value = 0x08;
}

void dumpDimmerMap()
{
  for(int i=0;i<256;i++)
    printf("%d => %d \r\n", i, pgm_read_byte_near(dimmerPwmMap + i)); 
}

void sendHeader(unsigned short msgType){
  radio.stopListening();

  messageType_t messageType;
  messageType.messageType = msgType;

  radio.write(&messageType, sizeof(messageType_t));
}

void sendStatus(){
      lastStatus = millis();
      sendHeader(MSGTYPE_FULL);
      
      // Send the final one back.
      radio.write( &statusReport, sizeof(statusReport_t) );
      printf("Sent response.\n\r");
}


bool waitForData(unsigned short timeoutMs)
{
  unsigned long started_waiting_at = millis();
  bool timeout = false;
  while ( ! radio.available() && ! timeout ) {
    timeout = (millis() - started_waiting_at > timeoutMs );
  }

  if(timeout)
    return false;

  return true;
}


void handleStatusRequest(){
  printf("handleStatusRequest\r\n");
  
  statusReport.powerSupplyVoltageRaw = analogRead(A_VOLTAGE_PIN);
  statusReport.powerSupplyCurrentRaw = analogRead(A_CURRENT_PIN);

  sensors.requestTemperatures();

  statusReport.internalTemperatureC00 = (int)(sensors.getTempCByIndex(0) * 100.0);
  statusReport.externalTemperatureC00 = 0 ;

  statusReport.outputSwitchState = 0;
  for(short i=0;i<4;i++)
    statusReport.outputSwitchState += switchOutputs[i].state;
  
  statusReport.inputSwitchState = 0;
  statusReport.dimmer1Demand = dimmers[0].demand;
  statusReport.dimmer2Demand = dimmers[1].demand;
  statusReport.dimmer1Actual = dimmers[0].current;
  statusReport.dimmer2Actual = dimmers[1].current;

  printf("Sending State\r\n");
  printf("V     : %d \r\n", statusReport.powerSupplyVoltageRaw);
  printf("I     : %d \r\n", statusReport.powerSupplyCurrentRaw);
  printf("T int : %d \r\n", statusReport.internalTemperatureC00);
  printf("T ext : %d \r\n", statusReport.externalTemperatureC00);
   
  sendStatus();
}

void handleDimmerCommand(){
  printf("handleDimmerCommand\r\n");
  if(!waitForData(DEFAULT_TIMEOUT_MS)){
    printf("Timeout\r\n");
    return;
  }

  dimmerCommand_t dimmerCommand;
  radio.read(&dimmerCommand, sizeof(dimmerCommand_t));

  printf("Set dimmer %d to %d", dimmerCommand.dimmerNumber, dimmerCommand.dimmerLevel); 
  switch(dimmerCommand.dimmerNumber){
    case 0:
    case 1:
      dimmers[dimmerCommand.dimmerNumber].demand = dimmerCommand.dimmerLevel;
      sendHeader(MSGTYPE_ACK_DIMMER);
      break;

    default:
      sendHeader(MSGTYPE_NACK);
      printf("Dimmer %d is out of range \r\n");
  }

  return;
}


void handleSwitchCommand(){
  printf("handleSwitchCommand\r\n");

  if(!waitForData(DEFAULT_TIMEOUT_MS)){
    printf("Timeout\r\n");
    return;
  }

  switchCommand_t switchCommand;
  radio.read(&switchCommand, sizeof(switchCommand_t));

  switch(switchCommand.id)
  {
    case 0:
    case 1:
    case 2:
    case 3:
      printf("Switch %d, set to %d \r\n", switchCommand.id, switchCommand.state);
      printf("Switch %d on pin %d \r\n", switchCommand.id, switchOutputs[switchCommand.id].pin);
      
      switchOutputs[switchCommand.id].state = switchCommand.state == 0 ? 0 : switchOutputs[switchCommand.id].value;
      digitalWrite(switchOutputs[switchCommand.id].pin, switchOutputs[switchCommand.id].state == 0 ? HIGH : LOW);
      sendHeader(MSGTYPE_ACK_SWITCH);
      break;
      
    default:
      sendHeader(MSGTYPE_NACK);
  }

  
  return;
}


void handleMessage(unsigned short messageType) {
  switch(messageType) {
    case MSGTYPE_CMD_STATUS_REQUEST:
      handleStatusRequest();
      break;

    case MSGTYPE_CMD_DIMMER:
      handleDimmerCommand();
      break;

    case MSGTYPE_CMD_SWITCH:
      handleSwitchCommand();
      break;
      
    default:
      printf("Unrecognised message %d \r\n", messageType);
  }
}


bool updateDimmers()
{
  bool dimmerAdjusted = false;
  for(int i=0;i<2;i++)
  {
    int delta = 0;
    if(dimmers[i].demand > dimmers[i].current) delta = 1;
    if(dimmers[i].demand < dimmers[i].current) delta = -1;

    if(delta !=0){    
      dimmerAdjusted = true;
      dimmers[i].current += delta;
      int level = pgm_read_byte_near(dimmerPwmMap + dimmers[i].current); 
      analogWrite(dimmers[i].pin, level);
      printf("Dimmer %d, demanded %d, actual %d, level %d \r\n", i, dimmers[i].demand, dimmers[i].current, level); 
    }
  }

  return dimmerAdjusted;
}


void loop(void)
{
    // Now, resume listening so we catch the next packets.
    radio.startListening();

    // if there is data ready
    if ( radio.available() )
    {
      printf("Data!\r\n");
      // Dump the payloads until we've gotten everything
      unsigned short message;
      bool done;

      messageType_t messageType;
       
      done = false;
      while ( radio.available() )
      {
        // Fetch the payload, and see if this was the last one.
        radio.read( &messageType, sizeof(messageType_t) );
        handleMessage(messageType.messageType);
      }
   }

   if(!updateDimmers() && !radio.available())
   {
      delay(100);
   }

   if(millis() - lastStatus > STATUS_UPDATE_INTERVAL_MS) {
    handleStatusRequest();
   }
   
   
   //printf("V: %d  I: %d \r\n", analogRead(A_VOLTAGE_PIN), analogRead(A_CURRENT_PIN));
   
}

