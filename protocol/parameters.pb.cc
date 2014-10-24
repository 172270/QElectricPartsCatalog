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
  delete reqParameters::default_instance_;
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
  reqParameters::default_instance_ = new reqParameters();
  resParameters::default_instance_ = new resParameters();
  resAddParameter::default_instance_ = new resAddParameter();
  ParameterBasicInformation::default_instance_->InitAsDefaultInstance();
  Parameter::default_instance_->InitAsDefaultInstance();
  reqParameters::default_instance_->InitAsDefaultInstance();
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
    case 2:
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
const int Parameter::kSymbolFieldNumber;
const int Parameter::kConfigDataFieldNumber;
const int Parameter::kDescriptionFieldNumber;
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
  symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  configdata_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Parameter::~Parameter() {
  SharedDtor();
}

void Parameter::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete symbol_;
  }
  if (configdata_ != &::google::protobuf::internal::kEmptyString) {
    delete configdata_;
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
    if (has_symbol()) {
      if (symbol_ != &::google::protobuf::internal::kEmptyString) {
        symbol_->clear();
      }
    }
    if (has_configdata()) {
      if (configdata_ != &::google::protobuf::internal::kEmptyString) {
        configdata_->clear();
      }
    }
    if (has_description()) {
      if (description_ != &::google::protobuf::internal::kEmptyString) {
        description_->clear();
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
        if (input->ExpectTag(26)) goto parse_symbol;
        break;
      }

      // required string symbol = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_symbol:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_symbol()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_configData;
        break;
      }

      // required bytes configData = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_configData:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_configdata()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_description;
        break;
      }

      // optional string description = 5;
      case 5: {
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

  // required string symbol = 3;
  if (has_symbol()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->symbol(), output);
  }

  // required bytes configData = 4;
  if (has_configdata()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->configdata(), output);
  }

  // optional string description = 5;
  if (has_description()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->description(), output);
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

    // required string symbol = 3;
    if (has_symbol()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->symbol());
    }

    // required bytes configData = 4;
    if (has_configdata()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->configdata());
    }

    // optional string description = 5;
    if (has_description()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->description());
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
    if (from.has_symbol()) {
      set_symbol(from.symbol());
    }
    if (from.has_configdata()) {
      set_configdata(from.configdata());
    }
    if (from.has_description()) {
      set_description(from.description());
    }
  }
}

void Parameter::CopyFrom(const Parameter& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Parameter::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void Parameter::Swap(Parameter* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(symbol_, other->symbol_);
    std::swap(configdata_, other->configdata_);
    std::swap(description_, other->description_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Parameter::GetTypeName() const {
  return "protbuf.Parameter";
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

reqParameters::reqParameters()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void reqParameters::InitAsDefaultInstance() {
}

reqParameters::reqParameters(const reqParameters& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void reqParameters::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

reqParameters::~reqParameters() {
  SharedDtor();
}

void reqParameters::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void reqParameters::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const reqParameters& reqParameters::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_parameters_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_parameters_2eproto();
#endif
  return *default_instance_;
}

reqParameters* reqParameters::default_instance_ = NULL;

reqParameters* reqParameters::New() const {
  return new reqParameters;
}

void reqParameters::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool reqParameters::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
  }
  return true;
#undef DO_
}

void reqParameters::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
}

int reqParameters::ByteSize() const {
  int total_size = 0;

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void reqParameters::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const reqParameters*>(&from));
}

void reqParameters::MergeFrom(const reqParameters& from) {
  GOOGLE_CHECK_NE(&from, this);
}

void reqParameters::CopyFrom(const reqParameters& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool reqParameters::IsInitialized() const {

  return true;
}

void reqParameters::Swap(reqParameters* other) {
  if (other != this) {
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string reqParameters::GetTypeName() const {
  return "protbuf.reqParameters";
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
