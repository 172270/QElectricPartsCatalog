// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: stats.proto

#ifndef PROTOBUF_stats_2eproto__INCLUDED
#define PROTOBUF_stats_2eproto__INCLUDED

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

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_stats_2eproto();
void protobuf_AssignDesc_stats_2eproto();
void protobuf_ShutdownFile_stats_2eproto();

class QueryStats;

// ===================================================================

class QueryStats : public ::google::protobuf::MessageLite {
 public:
  QueryStats();
  virtual ~QueryStats();

  QueryStats(const QueryStats& from);

  inline QueryStats& operator=(const QueryStats& from) {
    CopyFrom(from);
    return *this;
  }

  static const QueryStats& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const QueryStats* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(QueryStats* other);

  // implements Message ----------------------------------------------

  QueryStats* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const QueryStats& from);
  void MergeFrom(const QueryStats& from);
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

  // required uint32 count = 2;
  inline bool has_count() const;
  inline void clear_count();
  static const int kCountFieldNumber = 2;
  inline ::google::protobuf::uint32 count() const;
  inline void set_count(::google::protobuf::uint32 value);

  // required uint32 totalTime = 3;
  inline bool has_totaltime() const;
  inline void clear_totaltime();
  static const int kTotalTimeFieldNumber = 3;
  inline ::google::protobuf::uint32 totaltime() const;
  inline void set_totaltime(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:QueryStats)
 private:
  inline void set_has_count();
  inline void clear_has_count();
  inline void set_has_totaltime();
  inline void clear_has_totaltime();

  ::google::protobuf::uint32 count_;
  ::google::protobuf::uint32 totaltime_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_stats_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_stats_2eproto();
  #endif
  friend void protobuf_AssignDesc_stats_2eproto();
  friend void protobuf_ShutdownFile_stats_2eproto();

  void InitAsDefaultInstance();
  static QueryStats* default_instance_;
};
// ===================================================================


// ===================================================================

// QueryStats

// required uint32 count = 2;
inline bool QueryStats::has_count() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void QueryStats::set_has_count() {
  _has_bits_[0] |= 0x00000001u;
}
inline void QueryStats::clear_has_count() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void QueryStats::clear_count() {
  count_ = 0u;
  clear_has_count();
}
inline ::google::protobuf::uint32 QueryStats::count() const {
  return count_;
}
inline void QueryStats::set_count(::google::protobuf::uint32 value) {
  set_has_count();
  count_ = value;
}

// required uint32 totalTime = 3;
inline bool QueryStats::has_totaltime() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void QueryStats::set_has_totaltime() {
  _has_bits_[0] |= 0x00000002u;
}
inline void QueryStats::clear_has_totaltime() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void QueryStats::clear_totaltime() {
  totaltime_ = 0u;
  clear_has_totaltime();
}
inline ::google::protobuf::uint32 QueryStats::totaltime() const {
  return totaltime_;
}
inline void QueryStats::set_totaltime(::google::protobuf::uint32 value) {
  set_has_totaltime();
  totaltime_ = value;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_stats_2eproto__INCLUDED
