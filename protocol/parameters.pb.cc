// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: parameters.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "parameters.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace protbuf {

void protobuf_ShutdownFile_parameters_2eproto() {
  delete ParameterBasicInformation::default_instance_;
  delete Parameter::default_instance_;
  delete resParameters::default_instance_;
  delete resAddParameter::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_parameters_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_parameters_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ParameterBasicInformation::default_instance_ = new ParameterBasicInformation();
  Parameter::default_instance_ = new Parameter();
  resParameters::default_instance_ = new resParameters();
  resAddParameter::default_instance_ = new resAddParameter();
  ParameterBasicInformation::default_instance_->InitAsDefaultInstance();
  Parameter::default_instance_->InitAsDefaultInstance();
  resParameters::default_instance_->InitAsDefaultInstance();
  resAddParameter::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_parameters_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_parameters_2eproto_once_);
void protobuf_AddDesc_parameters_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_parameters_2eproto_once_,
                 &protobuf_AddDesc_parameters_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_parameters_2eproto {
  StaticDescriptorInitializer_parameters_2eproto() {
    protobuf_AddDesc_parameters_2eproto();
  }
} static_descriptor_initializer_parameters_2eproto_;
#endif
bool addParameterReplay_IsValid(int value) {
  switch(value) {
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int ParameterBasicInformation::kIdFieldNumber;
#endif  // !_MSC_VER

ParameterBasicInformation::ParameterBasicInformation()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void ParameterBasicInformation::InitAsDefaultInstance() {
}

ParameterBasicInformation::ParameterBasicInformation(const ParameterBasicInformation& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void ParameterBasicInformation::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ParameterBasicInformation::~ParameterBasicInformation() {
  SharedDtor();
}

void ParameterBasicInformation::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void ParameterBasicInformation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ParameterBasicInformation& ParameterBasicInformation::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_parameters_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_parameters_2eproto();
#endif
  return *default_instance_;
}

ParameterBasicInformation* ParameterBasicInformation::default_instance_ = NULL;

ParameterBasicInformation* ParameterBasicInformation::New() const {
  return new ParameterBasicInformation;
}

void ParameterBasicInformation::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool ParameterBasicInformation::MergePartialFromCodedStream(
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

void ParameterBasicInformation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

}

int ParameterBasicInformation::ByteSize() const {
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

void ParameterBasicInformation::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const ParameterBasicInformation*>(&from));
}

void ParameterBasicInformation::MergeFrom(const ParameterBasicInformation& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
}

void ParameterBasicInformation::CopyFrom(const ParameterBasicInformation& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ParameterBasicInformation::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ParameterBasicInformation::Swap(ParameterBasicInformation* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string ParameterBasicInformation::GetTypeName() const {
  return "protbuf.ParameterBasicInformation";
}


// ===================================================================

#ifndef _MSC_VER
const int Parameter::kIdFieldNumber;
const int Parameter::kNameFieldNumber;
const int Parameter::kConfigDataFieldNumber;
#endif  // !_MSC_VER

Parameter::Parameter()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Parameter::InitAsDefaultInstance() {
}

Parameter::Parameter(const Parameter& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Parameter::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  configdata_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Parameter::~Parameter() {
  SharedDtor();
}

void Parameter::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (configdata_ != &::google::protobuf::internal::kEmptyString) {
    delete configdata_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void Parameter::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Parameter& Parameter::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_parameters_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_parameters_2eproto();
#endif
  return *default_instance_;
}

Parameter* Parameter::default_instance_ = NULL;

Parameter* Parameter::New() const {
  return new Parameter;
}

void Parameter::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    if (has_configdata()) {
      if (configdata_ != &::google::protobuf::internal::kEmptyString) {
        configdata_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Parameter::MergePartialFromCodedStream(
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
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_configData;
        break;
      }

      // required bytes configData = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_configData:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_configdata()));
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

void Parameter::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // required bytes configData = 3;
  if (has_configdata()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->configdata(), output);
  }

}

int Parameter::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
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

    // required bytes configData = 3;
    if (has_configdata()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->configdata());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Parameter::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Parameter*>(&from));
}

void Parameter::MergeFrom(const Parameter& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_configdata()) {
      set_configdata(from.configdata());
    }
  }
}

void Parameter::CopyFrom(const Parameter& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Parameter::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void Parameter::Swap(Parameter* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(configdata_, other->configdata_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Parameter::GetTypeName() const {
  return "protbuf.Parameter";
}


// ===================================================================

#ifndef _MSC_VER
const int resParameters::kParametersFieldNumber;
#endif  // !_MSC_VER

resParameters::resParameters()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void resParameters::InitAsDefaultInstance() {
}

resParameters::resParameters(const resParameters& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void resParameters::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

resParameters::~resParameters() {
  SharedDtor();
}

void resParameters::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void resParameters::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const resParameters& resParameters::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_parameters_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_parameters_2eproto();
#endif
  return *default_instance_;
}

resParameters* resParameters::default_instance_ = NULL;

resParameters* resParameters::New() const {
  return new resParameters;
}

void resParameters::Clear() {
  parameters_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool resParameters::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protbuf.Parameter parameters = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_parameters:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_parameters()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_parameters;
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

void resParameters::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .protbuf.Parameter parameters = 1;
  for (int i = 0; i < this->parameters_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->parameters(i), output);
  }

}

int resParameters::ByteSize() const {
  int total_size = 0;

  // repeated .protbuf.Parameter parameters = 1;
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

void resParameters::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const resParameters*>(&from));
}

void resParameters::MergeFrom(const resParameters& from) {
  GOOGLE_CHECK_NE(&from, this);
  parameters_.MergeFrom(from.parameters_);
}

void resParameters::CopyFrom(const resParameters& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool resParameters::IsInitialized() const {

  for (int i = 0; i < parameters_size(); i++) {
    if (!this->parameters(i).IsInitialized()) return false;
  }
  return true;
}

void resParameters::Swap(resParameters* other) {
  if (other != this) {
    parameters_.Swap(&other->parameters_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string resParameters::GetTypeName() const {
  return "protbuf.resParameters";
}


// ===================================================================

#ifndef _MSC_VER
const int resAddParameter::kReplayFieldNumber;
#endif  // !_MSC_VER

resAddParameter::resAddParameter()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void resAddParameter::InitAsDefaultInstance() {
}

resAddParameter::resAddParameter(const resAddParameter& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void resAddParameter::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

resAddParameter::~resAddParameter() {
  SharedDtor();
}

void resAddParameter::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void resAddParameter::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const resAddParameter& resAddParameter::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_parameters_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_parameters_2eproto();
#endif
  return *default_instance_;
}

resAddParameter* resAddParameter::default_instance_ = NULL;

resAddParameter* resAddParameter::New() const {
  return new resAddParameter;
}

void resAddParameter::Clear() {
  replay_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool resAddParameter::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protbuf.addParameterReplay replay = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_replay:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protbuf::addParameterReplay_IsValid(value)) {
            add_replay(static_cast< ::protbuf::addParameterReplay >(value));
          }
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedEnumNoInline(
                 input,
                 &::protbuf::addParameterReplay_IsValid,
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

void resAddParameter::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .protbuf.addParameterReplay replay = 1;
  for (int i = 0; i < this->replay_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->replay(i), output);
  }

}

int resAddParameter::ByteSize() const {
  int total_size = 0;

  // repeated .protbuf.addParameterReplay replay = 1;
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

void resAddParameter::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const resAddParameter*>(&from));
}

void resAddParameter::MergeFrom(const resAddParameter& from) {
  GOOGLE_CHECK_NE(&from, this);
  replay_.MergeFrom(from.replay_);
}

void resAddParameter::CopyFrom(const resAddParameter& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool resAddParameter::IsInitialized() const {

  return true;
}

void resAddParameter::Swap(resAddParameter* other) {
  if (other != this) {
    replay_.Swap(&other->replay_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string resAddParameter::GetTypeName() const {
  return "protbuf.resAddParameter";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protbuf

// @@protoc_insertion_point(global_scope)
