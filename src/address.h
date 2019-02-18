#include "main.h"
#include "array.h"

class Address{
  Array *arr;
  u8 index = 0;
  u8 mask = 1;

public:
  Address(u8 val=0);
  ~Address();

  static u8 intSize();
  static Address *from(Address *addr);
  static Address *oldOrNew(Address *addr, bool createNew);
};