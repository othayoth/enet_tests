// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TEST_TESTFB_H_
#define FLATBUFFERS_GENERATED_TEST_TESTFB_H_

#include "flatbuffers/flatbuffers.h"

namespace TestFb {

struct Vec2;

struct object_positions;
struct object_positionsBuilder;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Vec2 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;

 public:
  Vec2()
      : x_(0),
        y_(0) {
  }
  Vec2(float _x, float _y)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
FLATBUFFERS_STRUCT_END(Vec2, 8);

struct object_positions FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef object_positionsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_OBJ_1 = 4,
    VT_OBJ_2 = 6
  };
  const TestFb::Vec2 *obj_1() const {
    return GetStruct<const TestFb::Vec2 *>(VT_OBJ_1);
  }
  const TestFb::Vec2 *obj_2() const {
    return GetStruct<const TestFb::Vec2 *>(VT_OBJ_2);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<TestFb::Vec2>(verifier, VT_OBJ_1) &&
           VerifyField<TestFb::Vec2>(verifier, VT_OBJ_2) &&
           verifier.EndTable();
  }
};

struct object_positionsBuilder {
  typedef object_positions Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_obj_1(const TestFb::Vec2 *obj_1) {
    fbb_.AddStruct(object_positions::VT_OBJ_1, obj_1);
  }
  void add_obj_2(const TestFb::Vec2 *obj_2) {
    fbb_.AddStruct(object_positions::VT_OBJ_2, obj_2);
  }
  explicit object_positionsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<object_positions> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<object_positions>(end);
    return o;
  }
};

inline flatbuffers::Offset<object_positions> Createobject_positions(
    flatbuffers::FlatBufferBuilder &_fbb,
    const TestFb::Vec2 *obj_1 = 0,
    const TestFb::Vec2 *obj_2 = 0) {
  object_positionsBuilder builder_(_fbb);
  builder_.add_obj_2(obj_2);
  builder_.add_obj_1(obj_1);
  return builder_.Finish();
}

}  // namespace TestFb

#endif  // FLATBUFFERS_GENERATED_TEST_TESTFB_H_
