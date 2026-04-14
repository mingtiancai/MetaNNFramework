#ifndef METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_
#define METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_

#include <type_traits>

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

	template<template <typename> class T1, typename T2>
	struct FuncTemplateInputBase {
		using Type = typename T1<T2>::type;
	};

	template <template <typename> class T1, typename T2>
	using FuncTemplateInput = typename FuncTemplateInputBase<T1, T2>::Type;

	void TestFuncTemplateInput();

	template<bool AddOrRemoveRef>
	struct FuncTemplateOutput;

	template<>
	struct FuncTemplateOutput<true> {
		template <typename T>
		using Type = std::add_lvalue_reference<T>;
	};

	template<>
	struct FuncTemplateOutput<false> {
		template<typename T>
		using Type = std::remove_reference<T>;
	};

	template <typename T, bool AddOrRemoveRef>
	using FuncTemplateOutputType = typename FuncTemplateOutput<AddOrRemoveRef>::template Type<T>::type;

	template <typename T>
	using ResFalse = FuncTemplateOutputType<T, false>;

	template <typename T>
	using ResTrue = FuncTemplateOutputType<T, true>;

	void TestFuncTemplateOutput();

	template <bool B, typename T, typename F>
	struct ConditionalType {
		using Type = T;
	};

	template <typename T, typename F>
	struct ConditionalType<false, T, F> {
		using Type = F;
	};

	void TestConditionalType();

	struct A {

	};

	struct B {

	};

	template <typename T>
	struct FunctionSelector {
		constexpr static size_t value = 0;
	};

	template<>
	struct FunctionSelector<A> {
		constexpr static size_t value = 1;
	};

	template<>
	struct FunctionSelector<B> {
		constexpr static size_t value = 2;
	};

	template<typename T>
	constexpr size_t FunctionSelectorValue = 0;

	template<>
	constexpr size_t FunctionSelectorValue<A> = 1;

	template<>
	constexpr size_t FunctionSelectorValue<B> = 2;

	void TestFunctionSelector();

	template <bool Check, std::enable_if_t<Check>* = nullptr>
	auto FuncWithEnableIf() {
		return int(9);
	}

	template <bool Check, std::enable_if_t<!Check>* = nullptr>
	auto FuncWithEnableIf() {
		return float(9.0);
	}

	template<bool Check>
	auto WarpFuncWithEnableIf() {
		return FuncWithEnableIf<Check>();
	}

	template<bool Check>
	auto FuncConditionWarp() {
		if constexpr (Check) {
			return int(9);
		}
		else {
			return float(9.0);
		}
	}

	void TestFuncWithEnableIf();

	template <size_t Input>
	constexpr size_t OnesCount = (Input % 2) + OnesCount<Input / 2>;

	template<>
	constexpr size_t OnesCount<0> = 0;

	void TestLoop();


}  // namespace metann

#endif  // METANNFRAMEWORK_METANNFRAMEWORK_BASIC_META_TEMPLATE_SAMPLE_H_
