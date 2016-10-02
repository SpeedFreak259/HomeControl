import homeControl_pb2

refCmd = homeControl_pb2.DimmerCommand()
refCmd.level = 10
refCmd.channel = 20
refCmd.message = "Hello from C++!"

refData = refCmd.SerializeToString()

print("REF")
print(refData.encode('hex'))

deCmd = homeControl_pb2.DimmerCommand()
deCmd.ParseFromString(refData)

print("De-serialized")
print(deCmd.message)

print("From file")

cmd = homeControl_pb2.DimmerCommand()

try:
    f = open("../cpp/bin/hc.dat", "rb")
   
    data = f.read();

    print(data.encode('hex'))

    if(data == refData):
        print("RefData and file data strings match!")


    if(cmd.ParseFromString(data)):
        print(cmd.message)
    else:
        print("Unable to parse.")
        print(cmd.message)
    f.close()
except IOError:
    print "File error"
