# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: homeControl.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='homeControl.proto',
  package='homeControl',
  syntax='proto3',
  serialized_pb=_b('\n\x11homeControl.proto\x12\x0bhomeControl\"\xcc\x01\n\x12HomeControlCommand\x12\x33\n\rdimmerCommand\x18\x01 \x01(\x0b\x32\x1a.homeControl.DimmerCommandH\x00\x12\x33\n\rswitchCommand\x18\x02 \x01(\x0b\x32\x1a.homeControl.SwitchCommandH\x00\x12\x41\n\x14statusRequestCommand\x18\x03 \x01(\x0b\x32!.homeControl.StatusRequestCommandH\x00\x42\t\n\x07\x63ommand\"/\n\rDimmerCommand\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\x05\x12\r\n\x05level\x18\x02 \x01(\x05\"/\n\rSwitchCommand\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\x05\x12\r\n\x05state\x18\x02 \x01(\x08\"z\n\x14StatusRequestCommand\x12@\n\nstatusType\x18\x01 \x01(\x0e\x32,.homeControl.StatusRequestCommand.StatusType\" \n\nStatusType\x12\x08\n\x04NONE\x10\x00\x12\x08\n\x04\x46ULL\x10\x01\"\x8f\x02\n\x11HomeControlStatus\x12\x31\n\nelectrical\x18\x01 \x01(\x0b\x32\x1d.homeControl.ElectricalStatus\x12*\n\x07outputs\x18\x02 \x03(\x0b\x32\x19.homeControl.SwitchStatus\x12)\n\x06inputs\x18\x03 \x03(\x0b\x32\x19.homeControl.SwitchStatus\x12*\n\x07\x64immers\x18\x04 \x03(\x0b\x32\x19.homeControl.DimmerStatus\x12\x34\n\x0ctemperatures\x18\x05 \x03(\x0b\x32\x1e.homeControl.TemperatureStatus\x12\x0e\n\x06uptime\x18\x06 \x01(\x04\"/\n\x10\x45lectricalStatus\x12\r\n\x05volts\x18\x01 \x01(\x01\x12\x0c\n\x04\x61mps\x18\x02 \x01(\x01\".\n\x0cSwitchStatus\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\x05\x12\r\n\x05state\x18\x02 \x01(\x08\"I\n\x0c\x44immerStatus\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\x05\x12\x13\n\x0b\x64\x65mandLevel\x18\x02 \x01(\x05\x12\x13\n\x0b\x61\x63tualLevel\x18\x03 \x01(\x05\"<\n\x11TemperatureStatus\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\x05\x12\x16\n\x0eTemperatureC00\x18\x02 \x01(\x05\x62\x06proto3')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)



_STATUSREQUESTCOMMAND_STATUSTYPE = _descriptor.EnumDescriptor(
  name='StatusType',
  full_name='homeControl.StatusRequestCommand.StatusType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='NONE', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='FULL', index=1, number=1,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=429,
  serialized_end=461,
)
_sym_db.RegisterEnumDescriptor(_STATUSREQUESTCOMMAND_STATUSTYPE)


_HOMECONTROLCOMMAND = _descriptor.Descriptor(
  name='HomeControlCommand',
  full_name='homeControl.HomeControlCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='dimmerCommand', full_name='homeControl.HomeControlCommand.dimmerCommand', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='switchCommand', full_name='homeControl.HomeControlCommand.switchCommand', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='statusRequestCommand', full_name='homeControl.HomeControlCommand.statusRequestCommand', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='command', full_name='homeControl.HomeControlCommand.command',
      index=0, containing_type=None, fields=[]),
  ],
  serialized_start=35,
  serialized_end=239,
)


_DIMMERCOMMAND = _descriptor.Descriptor(
  name='DimmerCommand',
  full_name='homeControl.DimmerCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.DimmerCommand.channel', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='level', full_name='homeControl.DimmerCommand.level', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=241,
  serialized_end=288,
)


_SWITCHCOMMAND = _descriptor.Descriptor(
  name='SwitchCommand',
  full_name='homeControl.SwitchCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.SwitchCommand.channel', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='state', full_name='homeControl.SwitchCommand.state', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=290,
  serialized_end=337,
)


_STATUSREQUESTCOMMAND = _descriptor.Descriptor(
  name='StatusRequestCommand',
  full_name='homeControl.StatusRequestCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='statusType', full_name='homeControl.StatusRequestCommand.statusType', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _STATUSREQUESTCOMMAND_STATUSTYPE,
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=339,
  serialized_end=461,
)


_HOMECONTROLSTATUS = _descriptor.Descriptor(
  name='HomeControlStatus',
  full_name='homeControl.HomeControlStatus',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='electrical', full_name='homeControl.HomeControlStatus.electrical', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='outputs', full_name='homeControl.HomeControlStatus.outputs', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='inputs', full_name='homeControl.HomeControlStatus.inputs', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='dimmers', full_name='homeControl.HomeControlStatus.dimmers', index=3,
      number=4, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='temperatures', full_name='homeControl.HomeControlStatus.temperatures', index=4,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='uptime', full_name='homeControl.HomeControlStatus.uptime', index=5,
      number=6, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=464,
  serialized_end=735,
)


_ELECTRICALSTATUS = _descriptor.Descriptor(
  name='ElectricalStatus',
  full_name='homeControl.ElectricalStatus',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='volts', full_name='homeControl.ElectricalStatus.volts', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='amps', full_name='homeControl.ElectricalStatus.amps', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=737,
  serialized_end=784,
)


_SWITCHSTATUS = _descriptor.Descriptor(
  name='SwitchStatus',
  full_name='homeControl.SwitchStatus',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.SwitchStatus.channel', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='state', full_name='homeControl.SwitchStatus.state', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=786,
  serialized_end=832,
)


_DIMMERSTATUS = _descriptor.Descriptor(
  name='DimmerStatus',
  full_name='homeControl.DimmerStatus',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.DimmerStatus.channel', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='demandLevel', full_name='homeControl.DimmerStatus.demandLevel', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='actualLevel', full_name='homeControl.DimmerStatus.actualLevel', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=834,
  serialized_end=907,
)


_TEMPERATURESTATUS = _descriptor.Descriptor(
  name='TemperatureStatus',
  full_name='homeControl.TemperatureStatus',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.TemperatureStatus.channel', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TemperatureC00', full_name='homeControl.TemperatureStatus.TemperatureC00', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=909,
  serialized_end=969,
)

_HOMECONTROLCOMMAND.fields_by_name['dimmerCommand'].message_type = _DIMMERCOMMAND
_HOMECONTROLCOMMAND.fields_by_name['switchCommand'].message_type = _SWITCHCOMMAND
_HOMECONTROLCOMMAND.fields_by_name['statusRequestCommand'].message_type = _STATUSREQUESTCOMMAND
_HOMECONTROLCOMMAND.oneofs_by_name['command'].fields.append(
  _HOMECONTROLCOMMAND.fields_by_name['dimmerCommand'])
_HOMECONTROLCOMMAND.fields_by_name['dimmerCommand'].containing_oneof = _HOMECONTROLCOMMAND.oneofs_by_name['command']
_HOMECONTROLCOMMAND.oneofs_by_name['command'].fields.append(
  _HOMECONTROLCOMMAND.fields_by_name['switchCommand'])
_HOMECONTROLCOMMAND.fields_by_name['switchCommand'].containing_oneof = _HOMECONTROLCOMMAND.oneofs_by_name['command']
_HOMECONTROLCOMMAND.oneofs_by_name['command'].fields.append(
  _HOMECONTROLCOMMAND.fields_by_name['statusRequestCommand'])
_HOMECONTROLCOMMAND.fields_by_name['statusRequestCommand'].containing_oneof = _HOMECONTROLCOMMAND.oneofs_by_name['command']
_STATUSREQUESTCOMMAND.fields_by_name['statusType'].enum_type = _STATUSREQUESTCOMMAND_STATUSTYPE
_STATUSREQUESTCOMMAND_STATUSTYPE.containing_type = _STATUSREQUESTCOMMAND
_HOMECONTROLSTATUS.fields_by_name['electrical'].message_type = _ELECTRICALSTATUS
_HOMECONTROLSTATUS.fields_by_name['outputs'].message_type = _SWITCHSTATUS
_HOMECONTROLSTATUS.fields_by_name['inputs'].message_type = _SWITCHSTATUS
_HOMECONTROLSTATUS.fields_by_name['dimmers'].message_type = _DIMMERSTATUS
_HOMECONTROLSTATUS.fields_by_name['temperatures'].message_type = _TEMPERATURESTATUS
DESCRIPTOR.message_types_by_name['HomeControlCommand'] = _HOMECONTROLCOMMAND
DESCRIPTOR.message_types_by_name['DimmerCommand'] = _DIMMERCOMMAND
DESCRIPTOR.message_types_by_name['SwitchCommand'] = _SWITCHCOMMAND
DESCRIPTOR.message_types_by_name['StatusRequestCommand'] = _STATUSREQUESTCOMMAND
DESCRIPTOR.message_types_by_name['HomeControlStatus'] = _HOMECONTROLSTATUS
DESCRIPTOR.message_types_by_name['ElectricalStatus'] = _ELECTRICALSTATUS
DESCRIPTOR.message_types_by_name['SwitchStatus'] = _SWITCHSTATUS
DESCRIPTOR.message_types_by_name['DimmerStatus'] = _DIMMERSTATUS
DESCRIPTOR.message_types_by_name['TemperatureStatus'] = _TEMPERATURESTATUS

HomeControlCommand = _reflection.GeneratedProtocolMessageType('HomeControlCommand', (_message.Message,), dict(
  DESCRIPTOR = _HOMECONTROLCOMMAND,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.HomeControlCommand)
  ))
_sym_db.RegisterMessage(HomeControlCommand)

DimmerCommand = _reflection.GeneratedProtocolMessageType('DimmerCommand', (_message.Message,), dict(
  DESCRIPTOR = _DIMMERCOMMAND,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.DimmerCommand)
  ))
_sym_db.RegisterMessage(DimmerCommand)

SwitchCommand = _reflection.GeneratedProtocolMessageType('SwitchCommand', (_message.Message,), dict(
  DESCRIPTOR = _SWITCHCOMMAND,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.SwitchCommand)
  ))
_sym_db.RegisterMessage(SwitchCommand)

StatusRequestCommand = _reflection.GeneratedProtocolMessageType('StatusRequestCommand', (_message.Message,), dict(
  DESCRIPTOR = _STATUSREQUESTCOMMAND,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.StatusRequestCommand)
  ))
_sym_db.RegisterMessage(StatusRequestCommand)

HomeControlStatus = _reflection.GeneratedProtocolMessageType('HomeControlStatus', (_message.Message,), dict(
  DESCRIPTOR = _HOMECONTROLSTATUS,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.HomeControlStatus)
  ))
_sym_db.RegisterMessage(HomeControlStatus)

ElectricalStatus = _reflection.GeneratedProtocolMessageType('ElectricalStatus', (_message.Message,), dict(
  DESCRIPTOR = _ELECTRICALSTATUS,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.ElectricalStatus)
  ))
_sym_db.RegisterMessage(ElectricalStatus)

SwitchStatus = _reflection.GeneratedProtocolMessageType('SwitchStatus', (_message.Message,), dict(
  DESCRIPTOR = _SWITCHSTATUS,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.SwitchStatus)
  ))
_sym_db.RegisterMessage(SwitchStatus)

DimmerStatus = _reflection.GeneratedProtocolMessageType('DimmerStatus', (_message.Message,), dict(
  DESCRIPTOR = _DIMMERSTATUS,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.DimmerStatus)
  ))
_sym_db.RegisterMessage(DimmerStatus)

TemperatureStatus = _reflection.GeneratedProtocolMessageType('TemperatureStatus', (_message.Message,), dict(
  DESCRIPTOR = _TEMPERATURESTATUS,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.TemperatureStatus)
  ))
_sym_db.RegisterMessage(TemperatureStatus)


# @@protoc_insertion_point(module_scope)
