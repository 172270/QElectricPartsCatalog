// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: package.proto

#ifndef PROTOBUF_package_2eproto__INCLUDED
#define PROTOBUF_package_2eproto__INCLUDED

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

namespace package {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_package_2eproto();
void protobuf_AssignDesc_package_2eproto();
void protobuf_ShutdownFile_package_2eproto();

class Package;

// ===================================================================

class Package : public ::google::protobuf::MessageLite {
 public:
  Package();
  virtual ~Package();

  Package(const Package& from);

  inline Package& operator=(const Package& from) {
    CopyFrom(from);
    return *this;
  }

  static const Package& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Package* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Package* other);

  // implements Message ----------------------------------------------

  Package* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Package& from);
  void MergeFrom(const Package& from);
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

  // required uint32 ID = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIDFieldNumber = 1;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // required string name = 2;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 2;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:package.Package)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_name();
  inline void clear_has_name();

  ::std::string* name_;
  ::google::protobuf::uint32 id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_package_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_package_2eproto();
  #endif
  friend void protobuf_AssignDesc_package_2eproto();
  friend void protobuf_ShutdownFile_package_2eproto();

  void InitAsDefaultInstance();
  static Package* default_instance_;
};
// ===================================================================


// ===================================================================

// Package

// required uint32 ID = 1;
inline bool Package::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Package::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Package::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Package::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 Package::id() const {
  return id_;
}
inline void Package::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// required string name = 2;
inline bool Package::has_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Package::set_has_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Package::clear_has_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Package::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Package::name() const {
  return *name_;
}
inline void Package::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Package::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Package::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Package::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Package::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Package::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace package

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_package_2eproto__INCLUDED