#include "basic_meta_template_sample.h"

#include <iostream>
#include <typeinfo>

namespace metann_sample {

	void TestBasicMetaTemplate() {
		UnsignedTypeOrSelf<int>::Type int_value = 10;
		std::cout << typeid(int_value).name() << '\n';

		UnsignedTypeOrSelf<long>::Type long_value = 10;
		std::cout << typeid(long_value).name() << '\n';

		UnsignedTypeOrSelf<float>::Type float_value = 10;
		std::cout << typeid(float_value).name() << '\n';
	}

	void TestFuncTemplateInput() {
		FuncTemplateInput<std::remove_reference, int&> h = 3;
		std::cout << typeid(h).name() << '\n';
	}

	void TestFuncTemplateOutput()
	{
		int temp = 3;
		ResFalse<int&> a = temp;
		ResTrue<int> b = temp;

		std::cout << "a is reference: " << std::is_reference<decltype(a)>::value << '\n';
		std::cout << "b is reference: " << std::is_reference<decltype(b)>::value << '\n';
		std::cout << "a type: " << typeid(decltype(a)).name() << '\n';
		std::cout << "b type: " << typeid(decltype(b)).name() << '\n';
	}

	void TestConditionalType()
	{
		ConditionalType<true, int, float>::Type a = 3;
		ConditionalType<false, int, float>::Type b = 3;

		std::cout << "a type: " << typeid(a).name() << '\n';
		std::cout << "b type: " << typeid(b).name() << '\n';
	}

	void TestFunctionSelector()
	{
		constexpr size_t h1 = FunctionSelector<A>::value;
		constexpr size_t h2 = FunctionSelector<B>::value;

		std::cout << "FunctionSelector<A>::value = " << h1 << '\n';
		std::cout << "FunctionSelector<B>::value = " << h2 << '\n';

		constexpr size_t h3 = FunctionSelectorValue<A>;
		constexpr size_t h4 = FunctionSelectorValue<B>;

		std::cout << "FunctionSelectorValue<A> = " << h3 << '\n';
		std::cout << "FunctionSelectorValue<B> = " << h4 << '\n';
	}

	void TestFuncWithEnableIf()
	{
		std::cout << typeid(WarpFuncWithEnableIf<true>()).name() << std::endl;
		std::cout << typeid(WarpFuncWithEnableIf<false>()).name() << std::endl;

		std::cout << typeid(FuncConditionWarp<true>()).name() << std::endl;
		std::cout << typeid(FuncConditionWarp<false>()).name() << std::endl;
	}

	void TestLoop()
	{
		constexpr size_t res = OnesCount<45>;
		std::cout << "res: " << res << '\n';

		constexpr size_t acc = Accumulate<1, 2, 3, 4, 5>;
		std::cout << "acc: " << acc << '\n';

		constexpr size_t acc_empty = FuncAccumulate<1, 2, 3, 4, 5>();
		std::cout << "acc: " << acc_empty << '\n';
	}

	void TestCRTP()
	{
		Derive d;
		d.Func("implementation from derive class1");

		DeriveStatic d2;
		d2.Fun();
	}

}  // namespace metann
