#include "vector.h"
#include <iostream>
#include <assert.h>

bool test_constructors();

int main()
{

  bool passed = true;
  passed = test_constructors() && passed;

  if (passed) {
    std::cout << "SUCCESS: All tests passed" << std::endl;
  } else {
    std::cout << "FAILED: Some tests failed" << std::endl;
  }

  return 0;
}

template <typename TYPE, int DIMENSION>
void smoke_check(latc::Vector<TYPE, DIMENSION>& v) {
  std::cout << v << std::endl;
  std::cout << v.to_string() << std::endl;
  latc::Vector<TYPE, DIMENSION> v2(v);
  std::cout << v2 << std::endl;
  std::cout << v2.to_string() << std::endl;

}

bool test_constructors()
{
  {
    latc::Vector<int, 5> v;
    smoke_check(v);
  }
  {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    latc::Vector<int, 6> v(arr);
    smoke_check(v);
  }
  {
    latc::Vector<double, 6> v({1.633, -684901, 4923.42, 752.1/83.1, 5e8, 6});
    smoke_check(v);
  }

  return true;
}