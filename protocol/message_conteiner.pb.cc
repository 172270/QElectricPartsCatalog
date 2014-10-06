// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_conteiner.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "message_conteiner.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

void protobuf_ShutdownFile_message_5fconteiner_2eproto() {
  delete MessageMetadata::default_instance_;
  delete MessagePackage::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_message_5fconteiner_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_message_5fconteiner_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::protobuf_AddDesc_types_2eproto();
  MessageMetadata::default_instance_ = new MessageMetadata();
  MessagePackage::default_instance_ = new MessagePackage();
  MessageMetadata::default_instance_->InitAsDefaultInstance();
  MessagePackage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_message_5fconteiner_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_message_5fconteiner_2eproto_once_);
void protobuf_AddDesc_message_5fconteiner_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_message_5fconteiner_2eproto_once_,
                 &protobuf_AddDesc_message_5fconteiner_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_message_5fconteiner_2eproto {
  StaticDescriptorInitializer_message_5fconteiner_2eproto() {
    protobuf_AddDesc_message_5fconteiner_2eproto();
  }
} static_descriptor_initializer_message_5fconteiner_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int MessageMetadata::kLengthFieldNumber;
const int MessageMetadata::kMsgTypeFieldNumber;
const int MessageMetadata::kDataFieldNumber;
#endif  // !_MSC_VER

MessageMetadata::MessageMetadata()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void MessageMetadata::InitAsDefaultInstance() {
}

MessageMetadata::MessageMetadata(const MessageMetadata& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void MessageMetadata::SharedCtor() {
  _cached_size_ = 0;
  length_ = GOOGLE_ULONGLONG(0);
  msgtype_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageMetadata::~MessageMetadata() {
  SharedDtor();
}

void MessageMetadata::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void MessageMetadata::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const MessageMetadata& MessageMetadata::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_message_5fconteiner_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_message_5fconteiner_2eproto();
#endif
  return *default_instance_;
}

MessageMetadata* MessageMetadata::default_instance_ = NULL;

MessageMetadata* MessageMetadata::New() const {
  return new MessageMetadata;
}

void MessageMetadata::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    length_ = GOOGLE_ULONGLONG(0);
    msgtype_ = 1;
  }
  data_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool MessageMetadata::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed64 length = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &length_)));
          set_has_length();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_msgType;
        break;
      }

      // required .MsgType msgType = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_msgType:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::MsgType_IsValid(value)) {
            set_msgtype(static_cast< ::MsgType >(value));
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_data;
        break;
      }

      // repeated bytes data = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_data()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_data;
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

void MessageMetadata::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required fixed64 length = 1;
  if (has_length()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->length(), output);
  }

  // required .MsgType msgType = 2;
  if (has_msgtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->msgtype(), output);
  }

  // repeated bytes data = 3;
  for (int i = 0; i < this->data_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->data(i), output);
  }

}

int MessageMetadata::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed64 length = 1;
    if (has_length()) {
      total_size += 1 + 8;
    }

    // required .MsgType msgType = 2;
    if (has_msgtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->msgtype());
    }

  }
  // repeated bytes data = 3;
  total_size += 1 * this->data_size();
  for (int i = 0; i < this->data_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->data(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessageMetadata::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const MessageMetadata*>(&from));
}

void MessageMetadata::MergeFrom(const MessageMetadata& from) {
  GOOGLE_CHECK_NE(&from, this);
  data_.MergeFrom(from.data_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_length()) {
      set_length(from.length());
    }
    if (from.has_msgtype()) {
      set_msgtype(from.msgtype());
    }
  }
}

void MessageMetadata::CopyFrom(const MessageMetadata& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageMetadata::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void MessageMetadata::Swap(MessageMetadata* other) {
  if (other != this) {
    std::swap(length_, other->length_);
    std::swap(msgtype_, other->msgtype_);
    data_.Swap(&other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string MessageMetadata::GetTypeName() const {
  return "MessageMetadata";
}


// ===================================================================

#ifndef _MSC_VER
const int MessagePackage::kDataFieldNumber;
#endif  // !_MSC_VER

MessagePackage::MessagePackage()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void MessagePackage::InitAsDefaultInstance() {
}

MessagePackage::MessagePackage(const MessagePackage& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void MessagePackage::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessagePackage::~MessagePackage() {
  SharedDtor();
}

void MessagePackage::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void MessagePackage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const MessagePackage& MessagePackage::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_message_5fconteiner_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_message_5fconteiner_2eproto();
#endif
  return *default_instance_;
}

MessagePackage* MessagePackage::default_instance_ = NULL;

MessagePackage* MessagePackage::New() const {
  return new MessagePackage;
}

void MessagePackage::Clear() {
  data_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool MessagePackage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .MessageMetadata data = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_data()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_data;
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

void MessagePackage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .MessageMetadata data = 1;
  for (int i = 0; i < this->data_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->data(i), output);
  }

}

int MessagePackage::ByteSize() const {
  int total_size = 0;

  // repeated .MessageMetadata data = 1;
  total_size += 1 * this->data_size();
  for (int i = 0; i < this->data_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->data(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessagePackage::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const MessagePackage*>(&from));
}

void MessagePackage::MergeFrom(const MessagePackage& from) {
  GOOGLE_CHECK_NE(&from, this);
  data_.MergeFrom(from.data_);
}

void MessagePackage::CopyFrom(const MessagePackage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessagePackage::IsInitialized() const {

  for (int i = 0; i < data_size(); i++) {
    if (!this->data(i).IsInitialized()) return false;
  }
  return true;
}

void MessagePackage::Swap(MessagePackage* other) {
  if (other != this) {
    data_.Swap(&other->data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string MessagePackage::GetTypeName() const {
  return "MessagePackage";
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
