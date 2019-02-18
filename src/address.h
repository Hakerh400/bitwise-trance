#include "main.h"
#include "array.h"

extern u8 INT_SIZE;
extern u8 INT_MASK;
extern u8 HIGHEST_BIT;

class Address{
  Array *arr;
  u8 index = 0;
  u8 mask = 1;

public:
  Address(u8 val=0);
  ~Address();
};