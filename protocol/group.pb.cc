// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: group.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "group.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace protbuf {

void protobuf_ShutdownFile_group_2eproto() {
  delete GroupBasicInformation::default_instance_;
  delete Group::default_instance_;
  delete resGroups::default_instance_;
  delete addGroup::default_instance_;
  delete resAddGroup::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_group_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_group_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::protbuf::protobuf_AddDesc_parameters_2eproto();
  GroupBasicInformation::default_instance_ = new GroupBasicInformation();
  Group::default_instance_ = new Group();
  resGroups::default_instance_ = new resGroups();
  addGroup::default_instance_ = new addGroup();
  resAddGroup::default_instance_ = new resAddGroup();
  GroupBasicInformation::default_instance_->InitAsDefaultInstance();
  Group::default_instance_->InitAsDefaultInstance();
  resGroups::default_instance_->InitAsDefaultInstance();
  addGroup::default_instance_->InitAsDefaultInstance();
  resAddGroup::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_group_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_group_2eproto_once_);
void protobuf_AddDesc_group_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_group_2eproto_once_,
                 &protobuf_AddDesc_group_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_group_2eproto {
  StaticDescriptorInitializer_group_2eproto() {
    protobuf_AddDesc_group_2eproto();
  }
} static_descriptor_initializer_group_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int GroupBasicInformation::kIdFieldNumber;
#endif  // !_MSC_VER

GroupBasicInformation::GroupBasicInformation()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void GroupBasicInformation::InitAsDefaultInstance() {
}

GroupBasicInformation::GroupBasicInformation(const GroupBasicInformation& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void GroupBasicInformation::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GroupBasicInformation::~GroupBasicInformation() {
  SharedDtor();
}

void GroupBasicInformation::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void GroupBasicInformation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const GroupBasicInformation& GroupBasicInformation::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_group_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_group_2eproto();
#endif
  return *default_instance_;
}

GroupBasicInformation* GroupBasicInformation::default_instance_ = NULL;

GroupBasicInformation* GroupBasicInformation::New() const {
  return new GroupBasicInformation;
}

void GroupBasicInformation::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool GroupBasicInformation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void GroupBasicInformation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

}

int GroupBasicInformation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GroupBasicInformation::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const GroupBasicInformation*>(&from));
}

void GroupBasicInformation::MergeFrom(const GroupBasicInformation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
}

void GroupBasicInformation::CopyFrom(const GroupBasicInformation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GroupBasicInformation::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void GroupBasicInformation::Swap(GroupBasicInformation* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string GroupBasicInformation::GetTypeName() const {
  return "protbuf.GroupBasicInformation";
}


// ===================================================================

#ifndef _MSC_VER
const int Group::kNameFieldNumber;
const int Group::kIDFieldNumber;
const int Group::kParentIDFieldNumber;
const int Group::kAllowSetsFieldNumber;
const int Group::kAllowItemsFieldNumber;
const int Group::kParametersFieldNumber;
const int Group::kDescriptionFieldNumber;
const int Group::kCreationDateFieldNumber;
#endif  // !_MSC_VER

Group::Group()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Group::InitAsDefaultInstance() {
}

Group::Group(const Group& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Group::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  id_ = 0u;
  parentid_ = 0u;
  allowsets_ = false;
  allowitems_ = false;
  description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  creationdate_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Group::~Group() {
  SharedDtor();
}

void Group::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (description_ != &::google::protobuf::internal::kEmptyString) {
    delete description_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void Group::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Group& Group::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_group_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_group_2eproto();
#endif
  return *default_instance_;
}

Group* Group::default_instance_ = NULL;

Group* Group::New() const {
  return new Group;
}

void Group::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    id_ = 0u;
    parentid_ = 0u;
    allowsets_ = false;
    allowitems_ = false;
    if (has_description()) {
      if (description_ != &::google::protobuf::internal::kEmptyString) {
        description_->clear();
      }
    }
    creationdate_ = GOOGLE_ULONGLONG(0);
  }
  parameters_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Group::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_ID;
        break;
      }

      // required uint32 ID = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_ID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_parentID;
        break;
      }

      // required uint32 parentID = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_parentID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &parentid_)));
          set_has_parentid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_allowSets;
        break;
      }

      // required bool allowSets = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_allowSets:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allowsets_)));
          set_has_allowsets();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_allowItems;
        break;
      }

      // required bool allowItems = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_allowItems:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allowitems_)));
          set_has_allowitems();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_parameters;
        break;
      }

      // repeated .protbuf.ParameterBasicInformation parameters = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_parameters:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_parameters()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_parameters;
        if (input->ExpectTag(74)) goto parse_description;
        break;
      }

      // optional string description = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_description:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_description()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_creationDate;
        break;
      }

      // optional uint64 creationDate = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_creationDate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &creationdate_)));
          set_has_creationdate();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Group::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 3;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->name(), output);
  }

  // required uint32 ID = 4;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->id(), output);
  }

  // required uint32 parentID = 5;
  if (has_parentid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->parentid(), output);
  }

  // required bool allowSets = 6;
  if (has_allowsets()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->allowsets(), output);
  }

  // required bool allowItems = 7;
  if (has_allowitems()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->allowitems(), output);
  }

  // repeated .protbuf.ParameterBasicInformation parameters = 8;
  for (int i = 0; i < this->parameters_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      8, this->parameters(i), output);
  }

  // optional string description = 9;
  if (has_description()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      9, this->description(), output);
  }

  // optional uint64 creationDate = 10;
  if (has_creationdate()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(10, this->creationdate(), output);
  }

}

int Group::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 3;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required uint32 ID = 4;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required uint32 parentID = 5;
    if (has_parentid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->parentid());
    }

    // required bool allowSets = 6;
    if (has_allowsets()) {
      total_size += 1 + 1;
    }

    // required bool allowItems = 7;
    if (has_allowitems()) {
      total_size += 1 + 1;
    }

    // optional string description = 9;
    if (has_description()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->description());
    }

    // optional uint64 creationDate = 10;
    if (has_creationdate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->creationdate());
    }

  }
  // repeated .protbuf.ParameterBasicInformation parameters = 8;
  total_size += 1 * this->parameters_size();
  for (int i = 0; i < this->parameters_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->parameters(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Group::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Group*>(&from));
}

void Group::MergeFrom(const Group& from) {
  GOOGLE_CHECK_NE(&from, this);
  parameters_.MergeFrom(from.parameters_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_parentid()) {
      set_parentid(from.parentid());
    }
    if (from.has_allowsets()) {
      set_allowsets(from.allowsets());
    }
    if (from.has_allowitems()) {
      set_allowitems(from.allowitems());
    }
    if (from.has_description()) {
      set_description(from.description());
    }
    if (from.has_creationdate()) {
      set_creationdate(from.creationdate());
    }
  }
}

void Group::CopyFrom(const Group& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Group::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  for (int i = 0; i < parameters_size(); i++) {
    if (!this->parameters(i).IsInitialized()) return false;
  }
  return true;
}

void Group::Swap(Group* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(id_, other->id_);
    std::swap(parentid_, other->parentid_);
    std::swap(allowsets_, other->allowsets_);
    std::swap(allowitems_, other->allowitems_);
    parameters_.Swap(&other->parameters_);
    std::swap(description_, other->description_);
    std::swap(creationdate_, other->creationdate_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Group::GetTypeName() const {
  return "protbuf.Group";
}


// ===================================================================

#ifndef _MSC_VER
const int resGroups::kGroupsFieldNumber;
#endif  // !_MSC_VER

resGroups::resGroups()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void resGroups::InitAsDefaultInstance() {
}

resGroups::resGroups(const resGroups& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void resGroups::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

resGroups::~resGroups() {
  SharedDtor();
}

void resGroups::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void resGroups::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const resGroups& resGroups::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_group_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_group_2eproto();
#endif
  return *default_instance_;
}

resGroups* resGroups::default_instance_ = NULL;

resGroups* resGroups::New() const {
  return new resGroups;
}

void resGroups::Clear() {
  groups_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool resGroups::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protbuf.Group groups = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_groups:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_groups()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_groups;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void resGroups::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .protbuf.Group groups = 1;
  for (int i = 0; i < this->groups_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->groups(i), output);
  }

}

int resGroups::ByteSize() const {
  int total_size = 0;

  // repeated .protbuf.Group groups = 1;
  total_size += 1 * this->groups_size();
  for (int i = 0; i < this->groups_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->groups(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void resGroups::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const resGroups*>(&from));
}

void resGroups::MergeFrom(const resGroups& from) {
  GOOGLE_CHECK_NE(&from, this);
  groups_.MergeFrom(from.groups_);
}

void resGroups::CopyFrom(const resGroups& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool resGroups::IsInitialized() const {

  for (int i = 0; i < groups_size(); i++) {
    if (!this->groups(i).IsInitialized()) return false;
  }
  return true;
}

void resGroups::Swap(resGroups* other) {
  if (other != this) {
    groups_.Swap(&other->groups_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string resGroups::GetTypeName() const {
  return "protbuf.resGroups";
}


// ===================================================================

#ifndef _MSC_VER
const int addGroup::kNameFieldNumber;
const int addGroup::kParentIDFieldNumber;
const int addGroup::kAllowSetsFieldNumber;
const int addGroup::kAllowItemsFieldNumber;
const int addGroup::kParametersFieldNumber;
const int addGroup::kDescriptionFieldNumber;
#endif  // !_MSC_VER

addGroup::addGroup()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void addGroup::InitAsDefaultInstance() {
}

addGroup::addGroup(const addGroup& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void addGroup::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  parentid_ = 0u;
  allowsets_ = false;
  allowitems_ = false;
  description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

addGroup::~addGroup() {
  SharedDtor();
}

void addGroup::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (description_ != &::google::protobuf::internal::kEmptyString) {
    delete description_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void addGroup::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const addGroup& addGroup::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_group_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_group_2eproto();
#endif
  return *default_instance_;
}

addGroup* addGroup::default_instance_ = NULL;

addGroup* addGroup::New() const {
  return new addGroup;
}

void addGroup::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    parentid_ = 0u;
    allowsets_ = false;
    allowitems_ = false;
    if (has_description()) {
      if (description_ != &::google::protobuf::internal::kEmptyString) {
        description_->clear();
      }
    }
  }
  parameters_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool addGroup::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_parentID;
        break;
      }

      // required uint32 parentID = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_parentID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &parentid_)));
          set_has_parentid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_allowSets;
        break;
      }

      // required bool allowSets = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_allowSets:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allowsets_)));
          set_has_allowsets();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_allowItems;
        break;
      }

      // required bool allowItems = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_allowItems:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &allowitems_)));
          set_has_allowitems();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_parameters;
        break;
      }

      // repeated .protbuf.ParameterBasicInformation parameters = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_parameters:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_parameters()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_parameters;
        if (input->ExpectTag(74)) goto parse_description;
        break;
      }

      // optional string description = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_description:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_description()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void addGroup::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 3;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->name(), output);
  }

  // required uint32 parentID = 5;
  if (has_parentid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->parentid(), output);
  }

  // required bool allowSets = 6;
  if (has_allowsets()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->allowsets(), output);
  }

  // required bool allowItems = 7;
  if (has_allowitems()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->allowitems(), output);
  }

  // repeated .protbuf.ParameterBasicInformation parameters = 8;
  for (int i = 0; i < this->parameters_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      8, this->parameters(i), output);
  }

  // optional string description = 9;
  if (has_description()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      9, this->description(), output);
  }

}

int addGroup::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 3;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required uint32 parentID = 5;
    if (has_parentid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->parentid());
    }

    // required bool allowSets = 6;
    if (has_allowsets()) {
      total_size += 1 + 1;
    }

    // required bool allowItems = 7;
    if (has_allowitems()) {
      total_size += 1 + 1;
    }

    // optional string description = 9;
    if (has_description()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->description());
    }

  }
  // repeated .protbuf.ParameterBasicInformation parameters = 8;
  total_size += 1 * this->parameters_size();
  for (int i = 0; i < this->parameters_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->parameters(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void addGroup::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const addGroup*>(&from));
}

void addGroup::MergeFrom(const addGroup& from) {
  GOOGLE_CHECK_NE(&from, this);
  parameters_.MergeFrom(from.parameters_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_parentid()) {
      set_parentid(from.parentid());
    }
    if (from.has_allowsets()) {
      set_allowsets(from.allowsets());
    }
    if (from.has_allowitems()) {
      set_allowitems(from.allowitems());
    }
    if (from.has_description()) {
      set_description(from.description());
    }
  }
}

void addGroup::CopyFrom(const addGroup& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool addGroup::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  for (int i = 0; i < parameters_size(); i++) {
    if (!this->parameters(i).IsInitialized()) return false;
  }
  return true;
}

void addGroup::Swap(addGroup* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(parentid_, other->parentid_);
    std::swap(allowsets_, other->allowsets_);
    std::swap(allowitems_, other->allowitems_);
    parameters_.Swap(&other->parameters_);
    std::swap(description_, other->description_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string addGroup::GetTypeName() const {
  return "protbuf.addGroup";
}


// ===================================================================

bool resAddGroup_addGroupReplay_IsValid(int value) {
  switch(value) {
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const resAddGroup_addGroupReplay resAddGroup::addOk;
const resAddGroup_addGroupReplay resAddGroup::addGroupReplay_MIN;
const resAddGroup_addGroupReplay resAddGroup::addGroupReplay_MAX;
const int resAddGroup::addGroupReplay_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int resAddGroup::kReplayFieldNumber;
#endif  // !_MSC_VER

resAddGroup::resAddGroup()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void resAddGroup::InitAsDefaultInstance() {
}

resAddGroup::resAddGroup(const resAddGroup& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void resAddGroup::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

resAddGroup::~resAddGroup() {
  SharedDtor();
}

void resAddGroup::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void resAddGroup::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const resAddGroup& resAddGroup::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_group_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_group_2eproto();
#endif
  return *default_instance_;
}

resAddGroup* resAddGroup::default_instance_ = NULL;

resAddGroup* resAddGroup::New() const {
  return new resAddGroup;
}

void resAddGroup::Clear() {
  replay_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool resAddGroup::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protbuf.resAddGroup.addGroupReplay replay = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_replay:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protbuf::resAddGroup_addGroupReplay_IsValid(value)) {
            add_replay(static_cast< ::protbuf::resAddGroup_addGroupReplay >(value));
          }
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedEnumNoInline(
                 input,
                 &::protbuf::resAddGroup_addGroupReplay_IsValid,
                 this->mutable_replay())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(8)) goto parse_replay;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void resAddGroup::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .protbuf.resAddGroup.addGroupReplay replay = 1;
  for (int i = 0; i < this->replay_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->replay(i), output);
  }

}

int resAddGroup::ByteSize() const {
  int total_size = 0;

  // repeated .protbuf.resAddGroup.addGroupReplay replay = 1;
  {
    int data_size = 0;
    for (int i = 0; i < this->replay_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::EnumSize(
        this->replay(i));
    }
    total_size += 1 * this->replay_size() + data_size;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void resAddGroup::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const resAddGroup*>(&from));
}

void resAddGroup::MergeFrom(const resAddGroup& from) {
  GOOGLE_CHECK_NE(&from, this);
  replay_.MergeFrom(from.replay_);
}

void resAddGroup::CopyFrom(const resAddGroup& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool resAddGroup::IsInitialized() const {

  return true;
}

void resAddGroup::Swap(resAddGroup* other) {
  if (other != this) {
    replay_.Swap(&other->replay_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string resAddGroup::GetTypeName() const {
  return "protbuf.resAddGroup";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protbuf

// @@protoc_insertion_point(global_scope)
