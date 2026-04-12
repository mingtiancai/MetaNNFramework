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

}  // namespace metann
