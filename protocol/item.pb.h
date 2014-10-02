// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: item.proto

#ifndef PROTOBUF_item_2eproto__INCLUDED
#define PROTOBUF_item_2eproto__INCLUDED

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
#include "user.pb.h"
#include "group.pb.h"
#include "package.pb.h"
// @@protoc_insertion_point(includes)

namespace item {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_item_2eproto();
void protobuf_AssignDesc_item_2eproto();
void protobuf_ShutdownFile_item_2eproto();

class ItemParameters;
class Item;

// ===================================================================

class ItemParameters : public ::google::protobuf::MessageLite {
 public:
  ItemParameters();
  virtual ~ItemParameters();

  ItemParameters(const ItemParameters& from);

  inline ItemParameters& operator=(const ItemParameters& from) {
    CopyFrom(from);
    return *this;
  }

  static const ItemParameters& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const ItemParameters* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(ItemParameters* other);

  // implements Message ----------------------------------------------

  ItemParameters* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const ItemParameters& from);
  void MergeFrom(const ItemParameters& from);
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

  // required bytes value = 2;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 2;
  inline const ::std::string& value() const;
  inline void set_value(const ::std::string& value);
  inline void set_value(const char* value);
  inline void set_value(const void* value, size_t size);
  inline ::std::string* mutable_value();
  inline ::std::string* release_value();
  inline void set_allocated_value(::std::string* value);

  // @@protoc_insertion_point(class_scope:item.ItemParameters)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_value();
  inline void clear_has_value();

  ::std::string* value_;
  ::google::protobuf::uint32 id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_item_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_item_2eproto();
  #endif
  friend void protobuf_AssignDesc_item_2eproto();
  friend void protobuf_ShutdownFile_item_2eproto();

  void InitAsDefaultInstance();
  static ItemParameters* default_instance_;
};
// -------------------------------------------------------------------

class Item : public ::google::protobuf::MessageLite {
 public:
  Item();
  virtual ~Item();

  Item(const Item& from);

  inline Item& operator=(const Item& from) {
    CopyFrom(from);
    return *this;
  }

  static const Item& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Item* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Item* other);

  // implements Message ----------------------------------------------

  Item* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Item& from);
  void MergeFrom(const Item& from);
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

  // required .package.Package package = 2;
  inline bool has_package() const;
  inline void clear_package();
  static const int kPackageFieldNumber = 2;
  inline const ::package::Package& package() const;
  inline ::package::Package* mutable_package();
  inline ::package::Package* release_package();
  inline void set_allocated_package(::package::Package* package);

  // required .user.UserBasicData user = 3;
  inline bool has_user() const;
  inline void clear_user();
  static const int kUserFieldNumber = 3;
  inline const ::user::UserBasicData& user() const;
  inline ::user::UserBasicData* mutable_user();
  inline ::user::UserBasicData* release_user();
  inline void set_allocated_user(::user::UserBasicData* user);

  // required .groups.GroupBasicData group = 4;
  inline bool has_group() const;
  inline void clear_group();
  static const int kGroupFieldNumber = 4;
  inline const ::groups::GroupBasicData& group() const;
  inline ::groups::GroupBasicData* mutable_group();
  inline ::groups::GroupBasicData* release_group();
  inline void set_allocated_group(::groups::GroupBasicData* group);

  // required string name = 5;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 5;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required string symbol = 6;
  inline bool has_symbol() const;
  inline void clear_symbol();
  static const int kSymbolFieldNumber = 6;
  inline const ::std::string& symbol() const;
  inline void set_symbol(const ::std::string& value);
  inline void set_symbol(const char* value);
  inline void set_symbol(const char* value, size_t size);
  inline ::std::string* mutable_symbol();
  inline ::std::string* release_symbol();
  inline void set_allocated_symbol(::std::string* symbol);

  // required string namespace = 7;
  inline bool has_namespace_() const;
  inline void clear_namespace_();
  static const int kNamespaceFieldNumber = 7;
  inline const ::std::string& namespace_() const;
  inline void set_namespace_(const ::std::string& value);
  inline void set_namespace_(const char* value);
  inline void set_namespace_(const char* value, size_t size);
  inline ::std::string* mutable_namespace_();
  inline ::std::string* release_namespace_();
  inline void set_allocated_namespace_(::std::string* namespace_);

  // required bool privateItem = 8;
  inline bool has_privateitem() const;
  inline void clear_privateitem();
  static const int kPrivateItemFieldNumber = 8;
  inline bool privateitem() const;
  inline void set_privateitem(bool value);

  // required uint64 addDate = 11;
  inline bool has_adddate() const;
  inline void clear_adddate();
  static const int kAddDateFieldNumber = 11;
  inline ::google::protobuf::uint64 adddate() const;
  inline void set_adddate(::google::protobuf::uint64 value);

  // repeated .item.ItemParameters parameters = 20;
  inline int parameters_size() const;
  inline void clear_parameters();
  static const int kParametersFieldNumber = 20;
  inline const ::item::ItemParameters& parameters(int index) const;
  inline ::item::ItemParameters* mutable_parameters(int index);
  inline ::item::ItemParameters* add_parameters();
  inline const ::google::protobuf::RepeatedPtrField< ::item::ItemParameters >&
      parameters() const;
  inline ::google::protobuf::RepeatedPtrField< ::item::ItemParameters >*
      mutable_parameters();

  // @@protoc_insertion_point(class_scope:item.Item)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_package();
  inline void clear_has_package();
  inline void set_has_user();
  inline void clear_has_user();
  inline void set_has_group();
  inline void clear_has_group();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_symbol();
  inline void clear_has_symbol();
  inline void set_has_namespace_();
  inline void clear_has_namespace_();
  inline void set_has_privateitem();
  inline void clear_has_privateitem();
  inline void set_has_adddate();
  inline void clear_has_adddate();

  ::package::Package* package_;
  ::user::UserBasicData* user_;
  ::groups::GroupBasicData* group_;
  ::google::protobuf::uint32 id_;
  bool privateitem_;
  ::std::string* name_;
  ::std::string* symbol_;
  ::std::string* namespace__;
  ::google::protobuf::uint64 adddate_;
  ::google::protobuf::RepeatedPtrField< ::item::ItemParameters > parameters_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(10 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_item_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_item_2eproto();
  #endif
  friend void protobuf_AssignDesc_item_2eproto();
  friend void protobuf_ShutdownFile_item_2eproto();

  void InitAsDefaultInstance();
  static Item* default_instance_;
};
// ===================================================================


// ===================================================================

// ItemParameters

// required uint32 id = 1;
inline bool ItemParameters::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ItemParameters::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ItemParameters::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ItemParameters::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 ItemParameters::id() const {
  return id_;
}
inline void ItemParameters::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// required bytes value = 2;
inline bool ItemParameters::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ItemParameters::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ItemParameters::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ItemParameters::clear_value() {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    value_->clear();
  }
  clear_has_value();
}
inline const ::std::string& ItemParameters::value() const {
  return *value_;
}
inline void ItemParameters::set_value(const ::std::string& value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void ItemParameters::set_value(const char* value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void ItemParameters::set_value(const void* value, size_t size) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* ItemParameters::mutable_value() {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  return value_;
}
inline ::std::string* ItemParameters::release_value() {
  clear_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = value_;
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void ItemParameters::set_allocated_value(::std::string* value) {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  if (value) {
    set_has_value();
    value_ = value;
  } else {
    clear_has_value();
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// Item

// required uint32 id = 1;
inline bool Item::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Item::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Item::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Item::clear_id() {
  id_ = 0u;
  clear_has_id();
}
inline ::google::protobuf::uint32 Item::id() const {
  return id_;
}
inline void Item::set_id(::google::protobuf::uint32 value) {
  set_has_id();
  id_ = value;
}

// required .package.Package package = 2;
inline bool Item::has_package() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Item::set_has_package() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Item::clear_has_package() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Item::clear_package() {
  if (package_ != NULL) package_->::package::Package::Clear();
  clear_has_package();
}
inline const ::package::Package& Item::package() const {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return package_ != NULL ? *package_ : *default_instance().package_;
#else
  return package_ != NULL ? *package_ : *default_instance_->package_;
#endif
}
inline ::package::Package* Item::mutable_package() {
  set_has_package();
  if (package_ == NULL) package_ = new ::package::Package;
  return package_;
}
inline ::package::Package* Item::release_package() {
  clear_has_package();
  ::package::Package* temp = package_;
  package_ = NULL;
  return temp;
}
inline void Item::set_allocated_package(::package::Package* package) {
  delete package_;
  package_ = package;
  if (package) {
    set_has_package();
  } else {
    clear_has_package();
  }
}

// required .user.UserBasicData user = 3;
inline bool Item::has_user() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Item::set_has_user() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Item::clear_has_user() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Item::clear_user() {
  if (user_ != NULL) user_->::user::UserBasicData::Clear();
  clear_has_user();
}
inline const ::user::UserBasicData& Item::user() const {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return user_ != NULL ? *user_ : *default_instance().user_;
#else
  return user_ != NULL ? *user_ : *default_instance_->user_;
#endif
}
inline ::user::UserBasicData* Item::mutable_user() {
  set_has_user();
  if (user_ == NULL) user_ = new ::user::UserBasicData;
  return user_;
}
inline ::user::UserBasicData* Item::release_user() {
  clear_has_user();
  ::user::UserBasicData* temp = user_;
  user_ = NULL;
  return temp;
}
inline void Item::set_allocated_user(::user::UserBasicData* user) {
  delete user_;
  user_ = user;
  if (user) {
    set_has_user();
  } else {
    clear_has_user();
  }
}

// required .groups.GroupBasicData group = 4;
inline bool Item::has_group() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Item::set_has_group() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Item::clear_has_group() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Item::clear_group() {
  if (group_ != NULL) group_->::groups::GroupBasicData::Clear();
  clear_has_group();
}
inline const ::groups::GroupBasicData& Item::group() const {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return group_ != NULL ? *group_ : *default_instance().group_;
#else
  return group_ != NULL ? *group_ : *default_instance_->group_;
#endif
}
inline ::groups::GroupBasicData* Item::mutable_group() {
  set_has_group();
  if (group_ == NULL) group_ = new ::groups::GroupBasicData;
  return group_;
}
inline ::groups::GroupBasicData* Item::release_group() {
  clear_has_group();
  ::groups::GroupBasicData* temp = group_;
  group_ = NULL;
  return temp;
}
inline void Item::set_allocated_group(::groups::GroupBasicData* group) {
  delete group_;
  group_ = group;
  if (group) {
    set_has_group();
  } else {
    clear_has_group();
  }
}

// required string name = 5;
inline bool Item::has_name() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Item::set_has_name() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Item::clear_has_name() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Item::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Item::name() const {
  return *name_;
}
inline void Item::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Item::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Item::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Item::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Item::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Item::set_allocated_name(::std::string* name) {
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

// required string symbol = 6;
inline bool Item::has_symbol() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Item::set_has_symbol() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Item::clear_has_symbol() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Item::clear_symbol() {
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    symbol_->clear();
  }
  clear_has_symbol();
}
inline const ::std::string& Item::symbol() const {
  return *symbol_;
}
inline void Item::set_symbol(const ::std::string& value) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(value);
}
inline void Item::set_symbol(const char* value) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(value);
}
inline void Item::set_symbol(const char* value, size_t size) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Item::mutable_symbol() {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  return symbol_;
}
inline ::std::string* Item::release_symbol() {
  clear_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = symbol_;
    symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Item::set_allocated_symbol(::std::string* symbol) {
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete symbol_;
  }
  if (symbol) {
    set_has_symbol();
    symbol_ = symbol;
  } else {
    clear_has_symbol();
    symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string namespace = 7;
inline bool Item::has_namespace_() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Item::set_has_namespace_() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Item::clear_has_namespace_() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Item::clear_namespace_() {
  if (namespace__ != &::google::protobuf::internal::kEmptyString) {
    namespace__->clear();
  }
  clear_has_namespace_();
}
inline const ::std::string& Item::namespace_() const {
  return *namespace__;
}
inline void Item::set_namespace_(const ::std::string& value) {
  set_has_namespace_();
  if (namespace__ == &::google::protobuf::internal::kEmptyString) {
    namespace__ = new ::std::string;
  }
  namespace__->assign(value);
}
inline void Item::set_namespace_(const char* value) {
  set_has_namespace_();
  if (namespace__ == &::google::protobuf::internal::kEmptyString) {
    namespace__ = new ::std::string;
  }
  namespace__->assign(value);
}
inline void Item::set_namespace_(const char* value, size_t size) {
  set_has_namespace_();
  if (namespace__ == &::google::protobuf::internal::kEmptyString) {
    namespace__ = new ::std::string;
  }
  namespace__->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Item::mutable_namespace_() {
  set_has_namespace_();
  if (namespace__ == &::google::protobuf::internal::kEmptyString) {
    namespace__ = new ::std::string;
  }
  return namespace__;
}
inline ::std::string* Item::release_namespace_() {
  clear_has_namespace_();
  if (namespace__ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = namespace__;
    namespace__ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Item::set_allocated_namespace_(::std::string* namespace_) {
  if (namespace__ != &::google::protobuf::internal::kEmptyString) {
    delete namespace__;
  }
  if (namespace_) {
    set_has_namespace_();
    namespace__ = namespace_;
  } else {
    clear_has_namespace_();
    namespace__ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bool privateItem = 8;
inline bool Item::has_privateitem() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Item::set_has_privateitem() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Item::clear_has_privateitem() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Item::clear_privateitem() {
  privateitem_ = false;
  clear_has_privateitem();
}
inline bool Item::privateitem() const {
  return privateitem_;
}
inline void Item::set_privateitem(bool value) {
  set_has_privateitem();
  privateitem_ = value;
}

// required uint64 addDate = 11;
inline bool Item::has_adddate() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Item::set_has_adddate() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Item::clear_has_adddate() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Item::clear_adddate() {
  adddate_ = GOOGLE_ULONGLONG(0);
  clear_has_adddate();
}
inline ::google::protobuf::uint64 Item::adddate() const {
  return adddate_;
}
inline void Item::set_adddate(::google::protobuf::uint64 value) {
  set_has_adddate();
  adddate_ = value;
}

// repeated .item.ItemParameters parameters = 20;
inline int Item::parameters_size() const {
  return parameters_.size();
}
inline void Item::clear_parameters() {
  parameters_.Clear();
}
inline const ::item::ItemParameters& Item::parameters(int index) const {
  return parameters_.Get(index);
}
inline ::item::ItemParameters* Item::mutable_parameters(int index) {
  return parameters_.Mutable(index);
}
inline ::item::ItemParameters* Item::add_parameters() {
  return parameters_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::item::ItemParameters >&
Item::parameters() const {
  return parameters_;
}
inline ::google::protobuf::RepeatedPtrField< ::item::ItemParameters >*
Item::mutable_parameters() {
  return &parameters_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace item

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_item_2eproto__INCLUDED