#include "address.h"

u8 INT_SIZE = 8;
u8 INT_MASK = (1 << INT_SIZE) - 1;
u8 HIGHEST_BIT = 1 << INT_SIZE - 1;

Address::Address(u8 val){
  arr = new List();
}

Address::~Address(){
  delete arr;
  arr = nullptr;
}