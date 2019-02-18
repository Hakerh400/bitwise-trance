#include "main.h"
#include "list.h"

extern u8 INT_SIZE;
extern u8 INT_MASK;
extern u8 HIGHEST_BIT;

class Address{
  List *arr;
  u8 index = 0;
  u8 mask = 1;

public:
  Address(u8 val=0);
  ~Address();
};