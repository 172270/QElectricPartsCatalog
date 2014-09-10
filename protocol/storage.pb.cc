// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: storage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "storage.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace storage {

void protobuf_ShutdownFile_storage_2eproto() {
  delete Storage::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_storage_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_storage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  Storage::default_instance_ = new Storage();
  Storage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_storage_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_storage_2eproto_once_);
void protobuf_AddDesc_storage_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_storage_2eproto_once_,
                 &protobuf_AddDesc_storage_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_storage_2eproto {
  StaticDescriptorInitializer_storage_2eproto() {
    protobuf_AddDesc_storage_2eproto();
  }
} static_descriptor_initializer_storage_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int Storage::kMsgTypeFieldNumber;
const int Storage::kNameFieldNumber;
const int Storage::kIdFieldNumber;
const int Storage::kCreationDateFieldNumber;
#endif  // !_MSC_VER

Storage::Storage()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Storage::InitAsDefaultInstance() {
}

Storage::Storage(const Storage& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Storage::SharedCtor() {
  _cached_size_ = 0;
  msgtype_ = 16u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  id_ = 0u;
  creationdate_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Storage::~Storage() {
  SharedDtor();
}

void Storage::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void Storage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Storage& Storage::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_storage_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_storage_2eproto();
#endif
  return *default_instance_;
}

Storage* Storage::default_instance_ = NULL;

Storage* Storage::New() const {
  return new Storage;
}

void Storage::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    msgtype_ = 16u;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    id_ = 0u;
    creationdate_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Storage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 msgType = 1 [default = 16];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &msgtype_)));
          set_has_msgtype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_name;
        break;
      }

      // required string name = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_id;
        break;
      }

      // required uint32 id = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(41)) goto parse_creationDate;
        break;
      }

      // optional fixed64 creationDate = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_creationDate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
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

void Storage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 msgType = 1 [default = 16];
  if (has_msgtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->msgtype(), output);
  }

  // required string name = 3;
  if (has_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->name(), output);
  }

  // required uint32 id = 4;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->id(), output);
  }

  // optional fixed64 creationDate = 5;
  if (has_creationdate()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(5, this->creationdate(), output);
  }

}

int Storage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 msgType = 1 [default = 16];
    if (has_msgtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->msgtype());
    }

    // required string name = 3;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required uint32 id = 4;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional fixed64 creationDate = 5;
    if (has_creationdate()) {
      total_size += 1 + 8;
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Storage::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Storage*>(&from));
}

void Storage::MergeFrom(const Storage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_msgtype()) {
      set_msgtype(from.msgtype());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_creationdate()) {
      set_creationdate(from.creationdate());
    }
  }
}

void Storage::CopyFrom(const Storage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Storage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void Storage::Swap(Storage* other) {
  if (other != this) {
    std::swap(msgtype_, other->msgtype_);
    std::swap(name_, other->name_);
    std::swap(id_, other->id_);
    std::swap(creationdate_, other->creationdate_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Storage::GetTypeName() const {
  return "storage.Storage";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace storage

// @@protoc_insertion_point(global_scope)