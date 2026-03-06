#ifndef METANNFRAMEWORK_METANNFRAMEWORK_BASICMETATEMPLATESAMPLE_H_
#define METANNFRAMEWORK_METANNFRAMEWORK_BASICMETATEMPLATESAMPLE_H_

constexpr int kCallCount = 3;

constexpr int Func(int a, bool b) {
  if (b) {
    return a + kCallCount;
  } else {
    return a - 1;
  }
}

constexpr int Func2(int a, bool b) {
  if (b) {
    return a + 1;
  } else {
    return a - 1;
  }
}

template <typename T>
struct Fun {
  using type = T;
};

template <>
struct Fun<int> {
  using type = unsigned int;
};

template <>
struct Fun<long> {
  using type = unsigned long;
};

void TestBasicMetaTemplate();

#endif  // METANNFRAMEWORK_METANNFRAMEWORK_BASICMETATEMPLATESAMPLE_H_
