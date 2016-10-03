import homeControl_pb2 as messages

cmd = messages.HomeControlCommand()

cmd.dimmerCommand.channel = 0
cmd.dimmerCommand.level = 127

cmd.switchCommand.channel = 4
cmd.switchCommand.state = True

cmd.statusRequestCommand.statusType = messages.StatusRequestCommand.FULL

s = cmd.SerializeToString()
print(''.join('{:02x}'.format(x) for x in s))
