#include "BasicMetaTemplateSample.h"

#include <iostream>
#include <typeinfo>

void TestBasicMetaTemplate() {
  Fun<int>::type a = 10;
  std::cout << typeid(a).name() << std::endl;

  Fun<long>::type b = 10;
  std::cout << typeid(b).name() << std::endl;

  Fun<float>::type c = 10;
  std::cout << typeid(c).name() << std::endl;
}