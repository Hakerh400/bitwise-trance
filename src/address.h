#pragma once

#include "main.h"
#include "array.h"
#include "elem.h"

class Address{
  Array *arr;
  u8 index = 0;
  u8 mask = 1;

public:
  Address(u8 val=0);
  ~Address();

  static u8 intSize();
  static Address *sfrom(Address *addr);
  static Address *oldOrNew(Address *addr, bool createNew);
  static Address *zero(bool createNew=0);
  static Address *one(bool createNew=0);

  u8 len();

  Address *fromArr(Array *arr);
  Address *from(Address *addr);
  Address *copy(Address *addr);
  Address *clone();
  Address *prepare();
  Address *push(bit b);
  Address *set(u8 val=0);
  Address *adapt(Address *addr);

  u1 cmp(Address *addr);
  bool eq(Address *addr);
  bool neq(Address *addr);
  bool lt(Address *addr);
  bool lte(Address *addr);
  bool gt(Address *addr);
  bool gte(Address *addr);

  Address *shl(u8 n=1);
  Address *shr(u8 n=1);
  Address *inc();
  Address *dec();
  Address *add(Address *addr);
  Address *sub(Address *addr);

  u8 valueOf();
};