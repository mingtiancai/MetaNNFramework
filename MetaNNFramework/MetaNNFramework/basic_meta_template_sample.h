#ifndef METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_
#define METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_

namespace metann {

constexpr int kCallCount = 3;

constexpr int AdjustByCallCount(int value, bool should_add) {
  if (should_add) {
    return value + kCallCount;
  }
  return value - 1;
}

constexpr int AdjustByOne(int value, bool should_add) {
  if (should_add) {
    return value + 1;
  }
  return value - 1;
}

template <typename T>
struct UnsignedTypeOrSelf {
  using Type = T;
};

template <>
struct UnsignedTypeOrSelf<int> {
  using Type = unsigned int;
};

template <>
struct UnsignedTypeOrSelf<long> {
  using Type = unsigned long;
};

void TestBasicMetaTemplate();

}  // namespace metann

#endif  // METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_
