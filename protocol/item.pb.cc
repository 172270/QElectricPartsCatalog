// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: item.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "item.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace protbuf {

void protobuf_ShutdownFile_item_2eproto() {
  delete ItemParameters::default_instance_;
  delete Item::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_item_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_item_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::protbuf::protobuf_AddDesc_user_2eproto();
  ::protbuf::protobuf_AddDesc_group_2eproto();
  ::protbuf::protobuf_AddDesc_package_2eproto();
  ::protbuf::protobuf_AddDesc_parameters_2eproto();
  ItemParameters::default_instance_ = new ItemParameters();
  Item::default_instance_ = new Item();
  ItemParameters::default_instance_->InitAsDefaultInstance();
  Item::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_item_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_item_2eproto_once_);
void protobuf_AddDesc_item_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_item_2eproto_once_,
                 &protobuf_AddDesc_item_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_item_2eproto {
  StaticDescriptorInitializer_item_2eproto() {
    protobuf_AddDesc_item_2eproto();
  }
} static_descriptor_initializer_item_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int ItemParameters::kIdFieldNumber;
const int ItemParameters::kValueFieldNumber;
#endif  // !_MSC_VER

ItemParameters::ItemParameters()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void ItemParameters::InitAsDefaultInstance() {
}

ItemParameters::ItemParameters(const ItemParameters& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void ItemParameters::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ItemParameters::~ItemParameters() {
  SharedDtor();
}

void ItemParameters::SharedDtor() {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void ItemParameters::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ItemParameters& ItemParameters::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_item_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_item_2eproto();
#endif
  return *default_instance_;
}

ItemParameters* ItemParameters::default_instance_ = NULL;

ItemParameters* ItemParameters::New() const {
  return new ItemParameters;
}

void ItemParameters::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0u;
    if (has_value()) {
      if (value_ != &::google::protobuf::internal::kEmptyString) {
        value_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool ItemParameters::MergePartialFromCodedStream(
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
        if (input->ExpectTag(18)) goto parse_value;
        break;
      }

      // required bytes value = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_value()));
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

void ItemParameters::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // required bytes value = 2;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->value(), output);
  }

}

int ItemParameters::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // required bytes value = 2;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->value());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ItemParameters::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const ItemParameters*>(&from));
}

void ItemParameters::MergeFrom(const ItemParameters& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_value()) {
      set_value(from.value());
    }
  }
}

void ItemParameters::CopyFrom(const ItemParameters& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ItemParameters::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void ItemParameters::Swap(ItemParameters* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(value_, other->value_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string ItemParameters::GetTypeName() const {
  return "protbuf.ItemParameters";
}


// ===================================================================

#ifndef _MSC_VER
const int Item::kIdFieldNumber;
const int Item::kNameFieldNumber;
const int Item::kSymbolFieldNumber;
const int Item::kNameSpaceFieldNumber;
const int Item::kPrivateItemFieldNumber;
const int Item::kPackageFieldNumber;
const int Item::kUserFieldNumber;
const int Item::kGroupFieldNumber;
const int Item::kAddDateFieldNumber;
const int Item::kUpdateDateFieldNumber;
const int Item::kDescriptionFieldNumber;
const int Item::kParametersFieldNumber;
#endif  // !_MSC_VER

Item::Item()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Item::InitAsDefaultInstance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  package_ = const_cast< ::protbuf::PackageBasicInformation*>(
      ::protbuf::PackageBasicInformation::internal_default_instance());
#else
  package_ = const_cast< ::protbuf::PackageBasicInformation*>(&::protbuf::PackageBasicInformation::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  user_ = const_cast< ::protbuf::UserBasicInformation*>(
      ::protbuf::UserBasicInformation::internal_default_instance());
#else
  user_ = const_cast< ::protbuf::UserBasicInformation*>(&::protbuf::UserBasicInformation::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  group_ = const_cast< ::protbuf::GroupBasicInformation*>(
      ::protbuf::GroupBasicInformation::internal_default_instance());
#else
  group_ = const_cast< ::protbuf::GroupBasicInformation*>(&::protbuf::GroupBasicInformation::default_instance());
#endif
}

Item::Item(const Item& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Item::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  name_space_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  privateitem_ = false;
  package_ = NULL;
  user_ = NULL;
  group_ = NULL;
  adddate_ = GOOGLE_ULONGLONG(0);
  updatedate_ = GOOGLE_ULONGLONG(0);
  description_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Item::~Item() {
  SharedDtor();
}

void Item::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete symbol_;
  }
  if (name_space_ != &::google::protobuf::internal::kEmptyString) {
    delete name_space_;
  }
  if (description_ != &::google::protobuf::internal::kEmptyString) {
    delete description_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
    delete package_;
    delete user_;
    delete group_;
  }
}

void Item::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Item& Item::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_item_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_item_2eproto();
#endif
  return *default_instance_;
}

Item* Item::default_instance_ = NULL;

Item* Item::New() const {
  return new Item;
}

void Item::Clear() {
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
    if (has_name_space()) {
      if (name_space_ != &::google::protobuf::internal::kEmptyString) {
        name_space_->clear();
      }
    }
    privateitem_ = false;
    if (has_package()) {
      if (package_ != NULL) package_->::protbuf::PackageBasicInformation::Clear();
    }
    if (has_user()) {
      if (user_ != NULL) user_->::protbuf::UserBasicInformation::Clear();
    }
    if (has_group()) {
      if (group_ != NULL) group_->::protbuf::GroupBasicInformation::Clear();
    }
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    adddate_ = GOOGLE_ULONGLONG(0);
    updatedate_ = GOOGLE_ULONGLONG(0);
    if (has_description()) {
      if (description_ != &::google::protobuf::internal::kEmptyString) {
        description_->clear();
      }
    }
  }
  parameters_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Item::MergePartialFromCodedStream(
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
        if (input->ExpectTag(34)) goto parse_name_space;
        break;
      }

      // required string name_space = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name_space:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name_space()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_privateItem;
        break;
      }

      // required bool privateItem = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_privateItem:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &privateitem_)));
          set_has_privateitem();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(82)) goto parse_package;
        break;
      }

      // required .protbuf.PackageBasicInformation package = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_package:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_package()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(90)) goto parse_user;
        break;
      }

      // required .protbuf.UserBasicInformation user = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_user:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_user()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(98)) goto parse_group;
        break;
      }

      // required .protbuf.GroupBasicInformation group = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_group:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_group()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(112)) goto parse_addDate;
        break;
      }

      // required uint64 addDate = 14;
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_addDate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &adddate_)));
          set_has_adddate();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(120)) goto parse_updateDate;
        break;
      }

      // required uint64 updateDate = 15;
      case 15: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_updateDate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &updatedate_)));
          set_has_updatedate();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(130)) goto parse_description;
        break;
      }

      // optional string description = 16;
      case 16: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_description:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_description()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(162)) goto parse_parameters;
        break;
      }

      // repeated .protbuf.ItemParameters parameters = 20;
      case 20: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_parameters:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_parameters()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(162)) goto parse_parameters;
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

void Item::SerializeWithCachedSizes(
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

  // required string name_space = 4;
  if (has_name_space()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->name_space(), output);
  }

  // required bool privateItem = 5;
  if (has_privateitem()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->privateitem(), output);
  }

  // required .protbuf.PackageBasicInformation package = 10;
  if (has_package()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      10, this->package(), output);
  }

  // required .protbuf.UserBasicInformation user = 11;
  if (has_user()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      11, this->user(), output);
  }

  // required .protbuf.GroupBasicInformation group = 12;
  if (has_group()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      12, this->group(), output);
  }

  // required uint64 addDate = 14;
  if (has_adddate()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(14, this->adddate(), output);
  }

  // required uint64 updateDate = 15;
  if (has_updatedate()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(15, this->updatedate(), output);
  }

  // optional string description = 16;
  if (has_description()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      16, this->description(), output);
  }

  // repeated .protbuf.ItemParameters parameters = 20;
  for (int i = 0; i < this->parameters_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      20, this->parameters(i), output);
  }

}

int Item::ByteSize() const {
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

    // required string name_space = 4;
    if (has_name_space()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name_space());
    }

    // required bool privateItem = 5;
    if (has_privateitem()) {
      total_size += 1 + 1;
    }

    // required .protbuf.PackageBasicInformation package = 10;
    if (has_package()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->package());
    }

    // required .protbuf.UserBasicInformation user = 11;
    if (has_user()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->user());
    }

    // required .protbuf.GroupBasicInformation group = 12;
    if (has_group()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->group());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // required uint64 addDate = 14;
    if (has_adddate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->adddate());
    }

    // required uint64 updateDate = 15;
    if (has_updatedate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->updatedate());
    }

    // optional string description = 16;
    if (has_description()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->description());
    }

  }
  // repeated .protbuf.ItemParameters parameters = 20;
  total_size += 2 * this->parameters_size();
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

void Item::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Item*>(&from));
}

void Item::MergeFrom(const Item& from) {
  GOOGLE_CHECK_NE(&from, this);
  parameters_.MergeFrom(from.parameters_);
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
    if (from.has_name_space()) {
      set_name_space(from.name_space());
    }
    if (from.has_privateitem()) {
      set_privateitem(from.privateitem());
    }
    if (from.has_package()) {
      mutable_package()->::protbuf::PackageBasicInformation::MergeFrom(from.package());
    }
    if (from.has_user()) {
      mutable_user()->::protbuf::UserBasicInformation::MergeFrom(from.user());
    }
    if (from.has_group()) {
      mutable_group()->::protbuf::GroupBasicInformation::MergeFrom(from.group());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_adddate()) {
      set_adddate(from.adddate());
    }
    if (from.has_updatedate()) {
      set_updatedate(from.updatedate());
    }
    if (from.has_description()) {
      set_description(from.description());
    }
  }
}

void Item::CopyFrom(const Item& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Item::IsInitialized() const {
  if ((_has_bits_[0] & 0x000003ff) != 0x000003ff) return false;

  if (has_package()) {
    if (!this->package().IsInitialized()) return false;
  }
  if (has_user()) {
    if (!this->user().IsInitialized()) return false;
  }
  if (has_group()) {
    if (!this->group().IsInitialized()) return false;
  }
  for (int i = 0; i < parameters_size(); i++) {
    if (!this->parameters(i).IsInitialized()) return false;
  }
  return true;
}

void Item::Swap(Item* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(symbol_, other->symbol_);
    std::swap(name_space_, other->name_space_);
    std::swap(privateitem_, other->privateitem_);
    std::swap(package_, other->package_);
    std::swap(user_, other->user_);
    std::swap(group_, other->group_);
    std::swap(adddate_, other->adddate_);
    std::swap(updatedate_, other->updatedate_);
    std::swap(description_, other->description_);
    parameters_.Swap(&other->parameters_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Item::GetTypeName() const {
  return "protbuf.Item";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protbuf

// @@protoc_insertion_point(global_scope)
