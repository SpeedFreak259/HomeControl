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
  serialized_pb=_b('\n\x11homeControl.proto\x12\x0bhomeControl\"/\n\rDimmerCommand\x12\x0f\n\x07\x63hannel\x18\x01 \x02(\x05\x12\r\n\x05level\x18\x02 \x02(\x05')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_DIMMERCOMMAND = _descriptor.Descriptor(
  name='DimmerCommand',
  full_name='homeControl.DimmerCommand',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='homeControl.DimmerCommand.channel', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='level', full_name='homeControl.DimmerCommand.level', index=1,
      number=2, type=5, cpp_type=1, label=2,
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
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=34,
  serialized_end=81,
)

DESCRIPTOR.message_types_by_name['DimmerCommand'] = _DIMMERCOMMAND

DimmerCommand = _reflection.GeneratedProtocolMessageType('DimmerCommand', (_message.Message,), dict(
  DESCRIPTOR = _DIMMERCOMMAND,
  __module__ = 'homeControl_pb2'
  # @@protoc_insertion_point(class_scope:homeControl.DimmerCommand)
  ))
_sym_db.RegisterMessage(DimmerCommand)


# @@protoc_insertion_point(module_scope)
