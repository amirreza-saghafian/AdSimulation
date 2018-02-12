//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "test_string_int.h"

int TestStringInt() {
  LruCache<std::string, int> string_int_cache(3);
  std::cout << string_int_cache.GetCapacity() << std::endl;
  int i = 1;
  string_int_cache.Insert("one", i);
  ++i;
  string_int_cache.Insert("two", i);
  ++i;
  string_int_cache.Insert("three", i);
  ++i;
  string_int_cache.Insert("four", i);
  ++i;
  string_int_cache.Insert("five", i);
  string_int_cache.Print();

  int num = string_int_cache.Lookup("five");
  std::cout << "num = " << num << std::endl;

  return 0;
}