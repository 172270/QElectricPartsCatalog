// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_conteiner.proto

#ifndef PROTOBUF_message_5fconteiner_2eproto__INCLUDED
#define PROTOBUF_message_5fconteiner_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_5fconteiner_2eproto();
void protobuf_AssignDesc_message_5fconteiner_2eproto();
void protobuf_ShutdownFile_message_5fconteiner_2eproto();

class package;

// ===================================================================

class package : public ::google::protobuf::MessageLite {
 public:
  package();
  virtual ~package();

  package(const package& from);

  inline package& operator=(const package& from) {
    CopyFrom(from);
    return *this;
  }

  static const package& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const package* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(package* other);

  // implements Message ----------------------------------------------

  package* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const package& from);
  void MergeFrom(const package& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required fixed64 length = 1;
  inline bool has_length() const;
  inline void clear_length();
  static const int kLengthFieldNumber = 1;
  inline ::google::protobuf::uint64 length() const;
  inline void set_length(::google::protobuf::uint64 value);

  // repeated bytes data = 2;
  inline int data_size() const;
  inline void clear_data();
  static const int kDataFieldNumber = 2;
  inline const ::std::string& data(int index) const;
  inline ::std::string* mutable_data(int index);
  inline void set_data(int index, const ::std::string& value);
  inline void set_data(int index, const char* value);
  inline void set_data(int index, const void* value, size_t size);
  inline ::std::string* add_data();
  inline void add_data(const ::std::string& value);
  inline void add_data(const char* value);
  inline void add_data(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& data() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_data();

  // @@protoc_insertion_point(class_scope:package)
 private:
  inline void set_has_length();
  inline void clear_has_length();

  ::google::protobuf::uint64 length_;
  ::google::protobuf::RepeatedPtrField< ::std::string> data_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_message_5fconteiner_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_message_5fconteiner_2eproto();
  #endif
  friend void protobuf_AssignDesc_message_5fconteiner_2eproto();
  friend void protobuf_ShutdownFile_message_5fconteiner_2eproto();

  void InitAsDefaultInstance();
  static package* default_instance_;
};
// ===================================================================


// ===================================================================

// package

// required fixed64 length = 1;
inline bool package::has_length() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void package::set_has_length() {
  _has_bits_[0] |= 0x00000001u;
}
inline void package::clear_has_length() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void package::clear_length() {
  length_ = GOOGLE_ULONGLONG(0);
  clear_has_length();
}
inline ::google::protobuf::uint64 package::length() const {
  return length_;
}
inline void package::set_length(::google::protobuf::uint64 value) {
  set_has_length();
  length_ = value;
}

// repeated bytes data = 2;
inline int package::data_size() const {
  return data_.size();
}
inline void package::clear_data() {
  data_.Clear();
}
inline const ::std::string& package::data(int index) const {
  return data_.Get(index);
}
inline ::std::string* package::mutable_data(int index) {
  return data_.Mutable(index);
}
inline void package::set_data(int index, const ::std::string& value) {
  data_.Mutable(index)->assign(value);
}
inline void package::set_data(int index, const char* value) {
  data_.Mutable(index)->assign(value);
}
inline void package::set_data(int index, const void* value, size_t size) {
  data_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* package::add_data() {
  return data_.Add();
}
inline void package::add_data(const ::std::string& value) {
  data_.Add()->assign(value);
}
inline void package::add_data(const char* value) {
  data_.Add()->assign(value);
}
inline void package::add_data(const void* value, size_t size) {
  data_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
package::data() const {
  return data_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
package::mutable_data() {
  return &data_;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_5fconteiner_2eproto__INCLUDED
