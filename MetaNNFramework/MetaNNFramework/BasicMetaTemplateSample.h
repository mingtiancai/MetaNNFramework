#pragma once

#include <typeinfo>
#include <iostream>

using namespace std;

static int call_count = 3;

constexpr int func(int a, bool b) {
	if (b)
		return a + call_count;
	else
		return a - 1;
}

constexpr int func2(int a, bool b) {
	if (b)
		return a + 1;
	else
		return a - 1;
}

template <typename T>
struct Fun_ { using type = T; };

template <>
struct Fun_<int> { using type = unsigned int; };

template <>
struct Fun_<long> { using type = unsigned long; };

void test_basic_meta_template();
