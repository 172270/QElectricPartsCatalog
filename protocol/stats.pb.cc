// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: stats.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "stats.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

void protobuf_ShutdownFile_stats_2eproto() {
  delete QueryStats::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_stats_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_stats_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  QueryStats::default_instance_ = new QueryStats();
  QueryStats::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_stats_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_stats_2eproto_once_);
void protobuf_AddDesc_stats_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_stats_2eproto_once_,
                 &protobuf_AddDesc_stats_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_stats_2eproto {
  StaticDescriptorInitializer_stats_2eproto() {
    protobuf_AddDesc_stats_2eproto();
  }
} static_descriptor_initializer_stats_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int QueryStats::kCountFieldNumber;
const int QueryStats::kTotalTimeFieldNumber;
#endif  // !_MSC_VER

QueryStats::QueryStats()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void QueryStats::InitAsDefaultInstance() {
}

QueryStats::QueryStats(const QueryStats& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void QueryStats::SharedCtor() {
  _cached_size_ = 0;
  count_ = 0u;
  totaltime_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QueryStats::~QueryStats() {
  SharedDtor();
}

void QueryStats::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void QueryStats::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const QueryStats& QueryStats::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_stats_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_stats_2eproto();
#endif
  return *default_instance_;
}

QueryStats* QueryStats::default_instance_ = NULL;

QueryStats* QueryStats::New() const {
  return new QueryStats;
}

void QueryStats::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    count_ = 0u;
    totaltime_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool QueryStats::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 count = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &count_)));
          set_has_count();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_totalTime;
        break;
      }

      // required uint32 totalTime = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_totalTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &totaltime_)));
          set_has_totaltime();
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

void QueryStats::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 count = 2;
  if (has_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->count(), output);
  }

  // required uint32 totalTime = 3;
  if (has_totaltime()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->totaltime(), output);
  }

}

int QueryStats::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 count = 2;
    if (has_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->count());
    }

    // required uint32 totalTime = 3;
    if (has_totaltime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->totaltime());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void QueryStats::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const QueryStats*>(&from));
}

void QueryStats::MergeFrom(const QueryStats& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_count()) {
      set_count(from.count());
    }
    if (from.has_totaltime()) {
      set_totaltime(from.totaltime());
    }
  }
}

void QueryStats::CopyFrom(const QueryStats& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QueryStats::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void QueryStats::Swap(QueryStats* other) {
  if (other != this) {
    std::swap(count_, other->count_);
    std::swap(totaltime_, other->totaltime_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string QueryStats::GetTypeName() const {
  return "QueryStats";
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
