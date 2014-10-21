// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: group.proto

#ifndef PROTOBUF_group_2eproto__INCLUDED
#define PROTOBUF_group_2eproto__INCLUDED

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
#include "parameters.pb.h"
// @@protoc_insertion_point(includes)

namespace protbuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_group_2eproto();
void protobuf_AssignDesc_group_2eproto();
void protobuf_ShutdownFile_group_2eproto();

class GroupBasicInformation;
class Group;
class reqGroups;
class resGroups;

// ===================================================================

class GroupBasicInformation : public ::google::protobuf::MessageLite {
 public:
  GroupBasicInformation();
  virtual ~GroupBasicInformation();

  GroupBasicInformation(const GroupBasicInformation& from);

  inline GroupBasicInformation& operator=(const GroupBasicInformation& from) {
    CopyFrom(from);
    return *this;
  }

  static const GroupBasicInformation& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const GroupBasicInformation* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(GroupBasicInformation* other);

  // implements Message ----------------------------------------------

  GroupBasicInformation* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const GroupBasicInformation& from);
  void MergeFrom(const GroupBasicInformation& from);
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

  // required uint32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protbuf.GroupBasicInformation)
 private:
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::uint32 id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_group_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_group_2eproto();
  #endif
  friend void protobuf_AssignDesc_group_2eproto();
  friend void protobuf_ShutdownFile_group_2eproto();

  void InitAsDefaultInstance();
  static GroupBasicInformation* default_instance_;
};
// -------------------------------------------------------------------

class Group : public ::google::protobuf::MessageLite {
 public:
  Group();
  virtual ~Group();

  Group(const Group& from);

  inline Group& operator=(const Group& from) {
    CopyFrom(from);
    return *this;
  }

  static const Group& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Group* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Group* other);

  // implements Message ----------------------------------------------

  Group* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Group& from);
  void MergeFrom(const Group& from);
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

  // required string name = 3;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 3;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required uint32 ID = 4;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIDFieldNumber = 4;
  inline ::google::protobuf::uint32 id() const;
  inline void set_id(::google::protobuf::uint32 value);

  // required uint32 parentID = 5;
  inline bool has_parentid() const;
  inline void clear_parentid();
  static const int kParentIDFieldNumber = 5;
  inline ::google::protobuf::uint32 parentid() const;
  inline void set_parentid(::google::protobuf::uint32 value);

  // required bool allowSets = 6;
  inline bool has_allowsets() const;
  inline void clear_allowsets();
  static const int kAllowSetsFieldNumber = 6;
  inline bool allowsets() const;
  inline void set_allowsets(bool value);

  // required bool allowItems = 7;
  inline bool has_allowitems() const;
  inline void clear_allowitems();
  static const int kAllowItemsFieldNumber = 7;
  inline bool allowitems() const;
  inline void set_allowitems(bool value);

  // repeated .protbuf.ParameterBasicInformation parameters = 8;
  inline int parameters_size() const;
  inline void clear_parameters();
  static const int kParametersFieldNumber = 8;
  inline const ::protbuf::ParameterBasicInformation& parameters(int index) const;
  inline ::protbuf::ParameterBasicInformation* mutable_parameters(int index);
  inline ::protbuf::ParameterBasicInformation* add_parameters();
  inline const ::google::protobuf::RepeatedPtrField< ::protbuf::ParameterBasicInformation >&
      parameters() const;
  inline ::google::protobuf::RepeatedPtrField< ::protbuf::ParameterBasicInformation >*
      mutable_parameters();

  // optional string description = 9;
  inline bool has_description() const;
  inline void clear_description();
  static const int kDescriptionFieldNumber = 9;
  inline const ::std::string& description() const;
  inline void set_description(const ::std::string& value);
  inline void set_description(const char* value);
  inline void set_description(const char* value, size_t size);
  inline ::std::string* mutable_description();
  inline ::std::string* release_description();
  inline void set_allocated_description(::std::string* description);

  // optional uint64 creationDate = 10;
  inline bool has_creationdate() const;
  inline void clear_creationdate();
  static const int kCreationDateFieldNumber = 10;
  inline ::google::protobuf::uint64 creationdate() const;
  inline void set_creationdate(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:protbuf.Group)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_parentid();
  inline void clear_has_parentid();
  inline void set_has_allowsets();
  inline void clear_has_allowsets();
  inline void set_has_allowitems();
  inline void clear_has_allowitems();
  inline void set_has_description();
  inline void clear_has_description();
  inline void set_has_creationdate();
  inline void clear_has_creationdate();

  ::std::string* name_;
  ::google::protobuf::uint32 id_;
  ::google::protobuf::uint32 parentid_;
  ::google::protobuf::RepeatedPtrField< ::protbuf::ParameterBasicInformation > parameters_;
  ::std::string* description_;
  ::google::protobuf::uint64 creationdate_;
  bool allowsets_;
  bool allowitems_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_group_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_group_2eproto();
  #endif
  friend void protobuf_AssignDesc_group_2eproto();
  friend void protobuf_ShutdownFile_group_2eproto();

  void InitAsDefaultInstance();
  static Group* default_instance_;
};
// -------------------------------------------------------------------

class reqGroups : public ::google::protobuf::MessageLite {
 public:
  reqGroups();
  virtual ~reqGroups();

  reqGroups(const reqGroups& from);

  inline reqGroups& operator=(const reqGroups& from) {
    CopyFrom(from);
    return *this;
  }

  static const reqGroups& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const reqGroups* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(reqGroups* other);

  // implements Message ----------------------------------------------

  reqGroups* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const reqGroups& from);
  void MergeFrom(const reqGroups& from);
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

  // @@protoc_insertion_point(class_scope:protbuf.reqGroups)
 private:


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_group_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_group_2eproto();
  #endif
  friend void protobuf_AssignDesc_group_2eproto();
  friend void protobuf_ShutdownFile_group_2eproto();

  void InitAsDefaultInstance();
  static reqGroups* default_instance_;
};
// -------------------------------------------------------------------

class resGroups : public ::google::protobuf::MessageLite {
 public:
  resGroups();
  virtual ~resGroups();

  resGroups(const resGroups& from);

  inline resGroups& operator=(const resGroups& from) {
    CopyFrom(from);
    return *this;
  }

  static const resGroups& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const resGroups* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(resGroups* other);

  // implements Message ----------------------------------------------

  resGroups* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const resGroups& from);
  void MergeFrom(const resGroups& from);
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

  // repeated .protbuf.Group groups = 1;
  inline int groups_size() const;
  inline void clear_groups();
  static const int kGroupsFieldNumber = 1;
  inline const ::protbuf::Group& groups(int index) const;
  inline ::protbuf::Group* mutable_groups(int index);
  inline ::protbuf::Group* add_groups();
  inline const ::google::protobuf::RepeatedPtrField< ::protbuf::Group >&
      groups() const;
  inline ::google::protobuf::RepeatedPtrField< ::protbuf::Group >*
      mutable_groups();

  // @@protoc_insertion_point(class_scope:protbuf.resGroups)
 private:

  ::google::protobuf::RepeatedPtrField< ::protbuf::Group > groups_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_group_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_group_2eproto();
  #endif
  friend void protobuf_AssignDesc_group_2eproto();
  friend void protobuf_ShutdownFile_group_2eproto();

  void InitAsDefaultInstance();
  static resGroups* default_instance_;
};
// ===================================================================


// ===================================================================

// GroupBasicInformation

// required uint32 id = 1;
inline bool GroupBasicInformation::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GroupBasicInformation::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GroupBasicInformation::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GroupBasicInformation::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 GroupBasicInformation::id() const {
  return id_;
}
inline void GroupBasicInformation::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// -------------------------------------------------------------------

// Group

// required string name = 3;
inline bool Group::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Group::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Group::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Group::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Group::name() const {
  return *name_;
}
inline void Group::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Group::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Group::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Group::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Group::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Group::set_allocated_name(::std::string* name) {
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

// required uint32 ID = 4;
inline bool Group::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Group::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Group::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Group::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 Group::id() const {
  return id_;
}
inline void Group::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// required uint32 parentID = 5;
inline bool Group::has_parentid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Group::set_has_parentid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Group::clear_has_parentid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Group::clear_parentid() {
  parentid_ = 0u;
  clear_has_parentid();
}
inline ::google::protobuf::uint32 Group::parentid() const {
  return parentid_;
}
inline void Group::set_parentid(::google::protobuf::uint32 value) {
  set_has_parentid();
  parentid_ = value;
}

// required bool allowSets = 6;
inline bool Group::has_allowsets() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Group::set_has_allowsets() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Group::clear_has_allowsets() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Group::clear_allowsets() {
  allowsets_ = false;
  clear_has_allowsets();
}
inline bool Group::allowsets() const {
  return allowsets_;
}
inline void Group::set_allowsets(bool value) {
  set_has_allowsets();
  allowsets_ = value;
}

// required bool allowItems = 7;
inline bool Group::has_allowitems() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Group::set_has_allowitems() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Group::clear_has_allowitems() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Group::clear_allowitems() {
  allowitems_ = false;
  clear_has_allowitems();
}
inline bool Group::allowitems() const {
  return allowitems_;
}
inline void Group::set_allowitems(bool value) {
  set_has_allowitems();
  allowitems_ = value;
}

// repeated .protbuf.ParameterBasicInformation parameters = 8;
inline int Group::parameters_size() const {
  return parameters_.size();
}
inline void Group::clear_parameters() {
  parameters_.Clear();
}
inline const ::protbuf::ParameterBasicInformation& Group::parameters(int index) const {
  return parameters_.Get(index);
}
inline ::protbuf::ParameterBasicInformation* Group::mutable_parameters(int index) {
  return parameters_.Mutable(index);
}
inline ::protbuf::ParameterBasicInformation* Group::add_parameters() {
  return parameters_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protbuf::ParameterBasicInformation >&
Group::parameters() const {
  return parameters_;
}
inline ::google::protobuf::RepeatedPtrField< ::protbuf::ParameterBasicInformation >*
Group::mutable_parameters() {
  return &parameters_;
}

// optional string description = 9;
inline bool Group::has_description() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Group::set_has_description() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Group::clear_has_description() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Group::clear_description() {
  if (description_ != &::google::protobuf::internal::kEmptyString) {
    description_->clear();
  }
  clear_has_description();
}
inline const ::std::string& Group::description() const {
  return *description_;
}
inline void Group::set_description(const ::std::string& value) {
  set_has_description();
  if (description_ == &::google::protobuf::internal::kEmptyString) {
    description_ = new ::std::string;
  }
  description_->assign(value);
}
inline void Group::set_description(const char* value) {
  set_has_description();
  if (description_ == &::google::protobuf::internal::kEmptyString) {
    description_ = new ::std::string;
  }
  description_->assign(value);
}
inline void Group::set_description(const char* value, size_t size) {
  set_has_description();
  if (description_ == &::google::protobuf::internal::kEmptyString) {
    description_ = new ::std::string;
  }
  description_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Group::mutable_description() {
  set_has_description();
  if (description_ == &::google::protobuf::internal::kEmptyString) {
    description_ = new ::std::string;
  }
  return description_;
}
inline ::std::string* Group::release_description() {
  clear_has_description();
  if (description_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = description_;
    description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Group::set_allocated_description(::std::string* description) {
  if (description_ != &::google::protobuf::internal::kEmptyString) {
    delete description_;
  }
  if (description) {
    set_has_description();
    description_ = description;
  } else {
    clear_has_description();
    description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint64 creationDate = 10;
inline bool Group::has_creationdate() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Group::set_has_creationdate() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Group::clear_has_creationdate() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Group::clear_creationdate() {
  creationdate_ = GOOGLE_ULONGLONG(0);
  clear_has_creationdate();
}
inline ::google::protobuf::uint64 Group::creationdate() const {
  return creationdate_;
}
inline void Group::set_creationdate(::google::protobuf::uint64 value) {
  set_has_creationdate();
  creationdate_ = value;
}

// -------------------------------------------------------------------

// reqGroups

// -------------------------------------------------------------------

// resGroups

// repeated .protbuf.Group groups = 1;
inline int resGroups::groups_size() const {
  return groups_.size();
}
inline void resGroups::clear_groups() {
  groups_.Clear();
}
inline const ::protbuf::Group& resGroups::groups(int index) const {
  return groups_.Get(index);
}
inline ::protbuf::Group* resGroups::mutable_groups(int index) {
  return groups_.Mutable(index);
}
inline ::protbuf::Group* resGroups::add_groups() {
  return groups_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protbuf::Group >&
resGroups::groups() const {
  return groups_;
}
inline ::google::protobuf::RepeatedPtrField< ::protbuf::Group >*
resGroups::mutable_groups() {
  return &groups_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protbuf

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_group_2eproto__INCLUDED
