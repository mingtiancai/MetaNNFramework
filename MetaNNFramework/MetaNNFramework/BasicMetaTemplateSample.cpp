#include "BasicMetaTemplateSample.h"


void test_basic_meta_template()
{
	Fun_<int>::type a = 10;
	std::cout << typeid(a).name() << std::endl;

	Fun_<long>::type b = 10;
	std::cout << typeid(b).name() << std::endl;

	Fun_<float>::type c = 10;
	std::cout << typeid(c).name() << std::endl;
}