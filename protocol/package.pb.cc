// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: package.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "package.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace package {

namespace {

const ::google::protobuf::Descriptor* PackageBasicInformation_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PackageBasicInformation_reflection_ = NULL;
const ::google::protobuf::Descriptor* Package_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Package_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_package_2eproto() {
  protobuf_AddDesc_package_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "package.proto");
  GOOGLE_CHECK(file != NULL);
  PackageBasicInformation_descriptor_ = file->message_type(0);
  static const int PackageBasicInformation_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackageBasicInformation, id_),
  };
  PackageBasicInformation_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PackageBasicInformation_descriptor_,
      PackageBasicInformation::default_instance_,
      PackageBasicInformation_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackageBasicInformation, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackageBasicInformation, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PackageBasicInformation));
  Package_descriptor_ = file->message_type(1);
  static const int Package_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, mounttype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, pinnumber_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, config_),
  };
  Package_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Package_descriptor_,
      Package::default_instance_,
      Package_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Package, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Package));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_package_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PackageBasicInformation_descriptor_, &PackageBasicInformation::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Package_descriptor_, &Package::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_package_2eproto() {
  delete PackageBasicInformation::default_instance_;
  delete PackageBasicInformation_reflection_;
  delete Package::default_instance_;
  delete Package_reflection_;
}

void protobuf_AddDesc_package_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rpackage.proto\022\007package\"%\n\027PackageBasic"
    "Information\022\n\n\002id\030\001 \002(\r\"Y\n\007Package\022\n\n\002ID"
    "\030\001 \002(\r\022\014\n\004name\030\002 \002(\t\022\021\n\tmountType\030\003 \001(\t\022"
    "\021\n\tpinNumber\030\004 \001(\r\022\016\n\006config\030\005 \001(\014", 154);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "package.proto", &protobuf_RegisterTypes);
  PackageBasicInformation::default_instance_ = new PackageBasicInformation();
  Package::default_instance_ = new Package();
  PackageBasicInformation::default_instance_->InitAsDefaultInstance();
  Package::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_package_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_package_2eproto {
  StaticDescriptorInitializer_package_2eproto() {
    protobuf_AddDesc_package_2eproto();
  }
} static_descriptor_initializer_package_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int PackageBasicInformation::kIdFieldNumber;
#endif  // !_MSC_VER

PackageBasicInformation::PackageBasicInformation()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PackageBasicInformation::InitAsDefaultInstance() {
}

PackageBasicInformation::PackageBasicInformation(const PackageBasicInformation& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PackageBasicInformation::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PackageBasicInformation::~PackageBasicInformation() {
  SharedDtor();
}

void PackageBasicInformation::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PackageBasicInformation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PackageBasicInformation::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PackageBasicInformation_descriptor_;
}

const PackageBasicInformation& PackageBasicInformation::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_package_2eproto();
  return *default_instance_;
}

PackageBasicInformation* PackageBasicInformation::default_instance_ = NULL;

PackageBasicInformation* PackageBasicInformation::New() const {
  return new PackageBasicInformation;
}

void PackageBasicInformation::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PackageBasicInformation::MergePartialFromCodedStream(
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PackageBasicInformation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PackageBasicInformation::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PackageBasicInformation::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PackageBasicInformation::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PackageBasicInformation* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PackageBasicInformation*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PackageBasicInformation::MergeFrom(const PackageBasicInformation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PackageBasicInformation::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PackageBasicInformation::CopyFrom(const PackageBasicInformation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PackageBasicInformation::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void PackageBasicInformation::Swap(PackageBasicInformation* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PackageBasicInformation::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PackageBasicInformation_descriptor_;
  metadata.reflection = PackageBasicInformation_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Package::kIDFieldNumber;
const int Package::kNameFieldNumber;
const int Package::kMountTypeFieldNumber;
const int Package::kPinNumberFieldNumber;
const int Package::kConfigFieldNumber;
#endif  // !_MSC_VER

Package::Package()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Package::InitAsDefaultInstance() {
}

Package::Package(const Package& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Package::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  mounttype_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  pinnumber_ = 0u;
  config_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Package::~Package() {
  SharedDtor();
}

void Package::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (mounttype_ != &::google::protobuf::internal::kEmptyString) {
    delete mounttype_;
  }
  if (config_ != &::google::protobuf::internal::kEmptyString) {
    delete config_;
  }
  if (this != default_instance_) {
  }
}

void Package::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Package::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Package_descriptor_;
}

const Package& Package::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_package_2eproto();
  return *default_instance_;
}

Package* Package::default_instance_ = NULL;

Package* Package::New() const {
  return new Package;
}

void Package::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    if (has_mounttype()) {
      if (mounttype_ != &::google::protobuf::internal::kEmptyString) {
        mounttype_->clear();
      }
    }
    pinnumber_ = 0u;
    if (has_config()) {
      if (config_ != &::google::protobuf::internal::kEmptyString) {
        config_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Package::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 ID = 1;
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
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // required string name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_mountType;
        break;
      }

      // optional string mountType = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_mountType:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_mounttype()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->mounttype().data(), this->mounttype().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_pinNumber;
        break;
      }

      // optional uint32 pinNumber = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_pinNumber:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &pinnumber_)));
          set_has_pinnumber();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_config;
        break;
      }

      // optional bytes config = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_config()));
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Package::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 ID = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // optional string mountType = 3;
  if (has_mounttype()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mounttype().data(), this->mounttype().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->mounttype(), output);
  }

  // optional uint32 pinNumber = 4;
  if (has_pinnumber()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->pinnumber(), output);
  }

  // optional bytes config = 5;
  if (has_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      5, this->config(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Package::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 ID = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional string mountType = 3;
  if (has_mounttype()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mounttype().data(), this->mounttype().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->mounttype(), target);
  }

  // optional uint32 pinNumber = 4;
  if (has_pinnumber()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->pinnumber(), target);
  }

  // optional bytes config = 5;
  if (has_config()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->config(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Package::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 ID = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional string mountType = 3;
    if (has_mounttype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->mounttype());
    }

    // optional uint32 pinNumber = 4;
    if (has_pinnumber()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->pinnumber());
    }

    // optional bytes config = 5;
    if (has_config()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->config());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Package::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Package* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Package*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Package::MergeFrom(const Package& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_mounttype()) {
      set_mounttype(from.mounttype());
    }
    if (from.has_pinnumber()) {
      set_pinnumber(from.pinnumber());
    }
    if (from.has_config()) {
      set_config(from.config());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Package::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Package::CopyFrom(const Package& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Package::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Package::Swap(Package* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(mounttype_, other->mounttype_);
    std::swap(pinnumber_, other->pinnumber_);
    std::swap(config_, other->config_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Package::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Package_descriptor_;
  metadata.reflection = Package_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace package

// @@protoc_insertion_point(global_scope)
