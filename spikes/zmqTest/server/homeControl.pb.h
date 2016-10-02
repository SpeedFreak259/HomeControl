// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: homeControl.proto

#ifndef PROTOBUF_homeControl_2eproto__INCLUDED
#define PROTOBUF_homeControl_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace homeControl {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_homeControl_2eproto();
void protobuf_AssignDesc_homeControl_2eproto();
void protobuf_ShutdownFile_homeControl_2eproto();

class DimmerCommand;

// ===================================================================

class DimmerCommand : public ::google::protobuf::Message {
 public:
  DimmerCommand();
  virtual ~DimmerCommand();

  DimmerCommand(const DimmerCommand& from);

  inline DimmerCommand& operator=(const DimmerCommand& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DimmerCommand& default_instance();

  void Swap(DimmerCommand* other);

  // implements Message ----------------------------------------------

  DimmerCommand* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DimmerCommand& from);
  void MergeFrom(const DimmerCommand& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 channel = 1;
  inline bool has_channel() const;
  inline void clear_channel();
  static const int kChannelFieldNumber = 1;
  inline ::google::protobuf::int32 channel() const;
  inline void set_channel(::google::protobuf::int32 value);

  // required int32 level = 2;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 2;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:homeControl.DimmerCommand)
 private:
  inline void set_has_channel();
  inline void clear_has_channel();
  inline void set_has_level();
  inline void clear_has_level();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 channel_;
  ::google::protobuf::int32 level_;
  friend void  protobuf_AddDesc_homeControl_2eproto();
  friend void protobuf_AssignDesc_homeControl_2eproto();
  friend void protobuf_ShutdownFile_homeControl_2eproto();

  void InitAsDefaultInstance();
  static DimmerCommand* default_instance_;
};
// ===================================================================


// ===================================================================

// DimmerCommand

// required int32 channel = 1;
inline bool DimmerCommand::has_channel() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DimmerCommand::set_has_channel() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DimmerCommand::clear_has_channel() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DimmerCommand::clear_channel() {
  channel_ = 0;
  clear_has_channel();
}
inline ::google::protobuf::int32 DimmerCommand::channel() const {
  // @@protoc_insertion_point(field_get:homeControl.DimmerCommand.channel)
  return channel_;
}
inline void DimmerCommand::set_channel(::google::protobuf::int32 value) {
  set_has_channel();
  channel_ = value;
  // @@protoc_insertion_point(field_set:homeControl.DimmerCommand.channel)
}

// required int32 level = 2;
inline bool DimmerCommand::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void DimmerCommand::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void DimmerCommand::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void DimmerCommand::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 DimmerCommand::level() const {
  // @@protoc_insertion_point(field_get:homeControl.DimmerCommand.level)
  return level_;
}
inline void DimmerCommand::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:homeControl.DimmerCommand.level)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace homeControl

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_homeControl_2eproto__INCLUDED