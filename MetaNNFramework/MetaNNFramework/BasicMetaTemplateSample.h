#pragma once

#include <iostream>
#include <typeinfo>

static int kCallCount = 3;

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
struct Fun_ {
  using type = T;
};

template <>
struct Fun_<int> {
  using type = unsigned int;
};

template <>
struct Fun_<long> {
  using type = unsigned long;
};

void TestBasicMetaTemplate();
