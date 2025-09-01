#include "vector.h"
#include <iostream>
#include <cassert>

#ifndef NDEBUG
#define DEBUG_VAR(var) \
    std::cout << #var << " = " << var << std::endl;
#else
// In release builds, the macro does nothing to avoid any overhead.
#define DEBUG_VAR(var) do {} while (0)
#endif

bool test_constructors();
bool test_get_set();
bool test_assign();

int main()
{

  bool passed = true;
  passed = test_constructors() && passed;
  passed = test_get_set() && passed;
  passed = test_assign() && passed;

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
    assert(v[0] == 0);
    assert(v[1] == 0);
    assert(v[2] == 0);
    assert(v[3] == 0);
    assert(v[4] == 0);
  }
  {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    latc::Vector<int, 6> v(arr);
    smoke_check(v);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 4);
    assert(v[4] == 5);
    assert(v[5] == 6);
  }
  {
    latc::Vector<double, 6> v({1.633, -684901, 4923.42, 752.1/83.1, 5e8, 6});
    smoke_check(v);
  }

  return true;
}

bool test_get_set() {
  {
    latc::Vector<int, 6> v({1, 2, 3, 4, 5, 6});
    assert(v[0] == 1);
    assert(v.get(1) == 2);
    DEBUG_VAR(v);
    v.set(2, 22);
    DEBUG_VAR(v);
    assert(v[2] == 22);
    v.set(5, 90);
    DEBUG_VAR(v);
    assert(v[5] == 90);
    v[4] = 55;
    DEBUG_VAR(v);
    assert(v.get(4) == 55);
  }

  return true;
}

bool test_assign() {
  {
    latc::Vector<int, 6> v({1, 2, 3, 4, 5, 6});
    latc::Vector<int, 6> v2;
    latc::Vector<int, 6> v3;
    assert(v[0] == 1);
    assert(v.get(1) == 2);
    assert(v2[0] == 0);
    assert(v2.get(1) == 0);
    assert(v3.get(1) == 0);
    DEBUG_VAR(v);
    DEBUG_VAR(v2);
    DEBUG_VAR(v3);
    v3 = v2 = v;
    v.set(2, 22);
    DEBUG_VAR(v2);
    DEBUG_VAR(v3);
    assert(v2[0] == 1);
    assert(v2.get(1) == 2);
    assert(v2.get(5) == 6);
    assert(v3.get(1) == 2);
    assert(v3.get(5) == 6);
  }

  return true;
}