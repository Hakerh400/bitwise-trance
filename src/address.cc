#include "address.h"

const u8 INT_SIZE = 8;
const u8 INT_MASK = (1 << INT_SIZE) - 1;
const u8 HIGHEST_BIT = 1 << INT_SIZE - 1;

Address::Address(u8 val){
  arr = new Array();

  //set(val);
}

Address::~Address(){
  delete arr;
  arr = nullptr;
}

u8 Address::intSize(){
  return INT_SIZE;
}

Address *Address::from(Address *addr){
  //return (new Address())->from(addr);
  return reinterpret_cast<Address*>((u8)0);
}

Address *Address::oldOrNew(Address *addr, bool createNew){
  //if(createNew) return addr->clone();
  return addr;
}

/*Address *Address::set(u8 val){

}*/