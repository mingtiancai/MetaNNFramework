#include "basic_meta_template_sample.h"

#include <iostream>
#include <typeinfo>

namespace metann {

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

}  // namespace metann
