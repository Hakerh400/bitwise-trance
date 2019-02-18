#include "address.h"

const u8 INT_SIZE = 8;
const u8 INT_MASK = (1 << INT_SIZE) - 1;
const u8 HIGHEST_BIT = 1 << INT_SIZE - 1;

Address *cnstZero = new Address(0);
Address *cnstOne = new Address(1);

Address::Address(u8 val){
  arr = new Array();

  set(val);
}

Address::~Address(){
  delete arr;
  arr = nullptr;
}

u8 Address::intSize(){
  return INT_SIZE;
}

Address *Address::sfrom(Address *addr){
  return (new Address())->from(addr);
}

Address *Address::oldOrNew(Address *addr, bool createNew){
  if(createNew) return addr->clone();
  return addr;
}

Address *Address::zero(bool createNew){
  return oldOrNew(cnstZero, createNew);
}

Address *Address::one(bool createNew){
  return oldOrNew(cnstOne, createNew);
}

u8 Address::len(){
  return arr->getLen();
}

Address *Address::fromArr(Array *arr){
  this->arr = arr->slice();
  return this;
}

Address *Address::from(Address *addr){
  return fromArr(addr->arr);
}

Address *Address::copy(Address *addr){
  return addr->from(this);
}

Address *Address::clone(){
  return sfrom(this);
}

Address *Address::prepare(){
  arr->setLen(0);
  arr->push(0);

  index = 0;
  mask = 1;

  return this;
}

Address *Address::push(bit b){
  if(b) arr->last() |= mask;

  if(mask != HIGHEST_BIT){
    mask <<= 1;
  }else{
    arr->push(0);
    mask = 1;
    index++;
  }

  return this;
}

Address *Address::set(u8 val){
  arr->setLen(0);

  while(val){
    arr->push(val & INT_MASK);
    val >>= INT_SIZE;
  }

  return this;
}

Address *Address::adapt(Address *addr){
  Array *arr1 = addr->arr;
  u8 len = arr->getLen();
  u8 len1 = arr1->getLen();

  if(len < len1){
    u8 dif = len1 - len;
    while(dif--) arr->push(0);
  }else if(len > len1){
    u8 dif = len - len1;
    while(dif--) arr1->push(0);
  }

  return this;
}

u1 Address::cmp(Address *addr){
  adapt(addr);

  Elem *e = arr->getTail();
  Elem *e1 = addr->arr->getTail();

  while(e){
    if(e->v < e1->v) return 0;
    if(e->v > e1->v) return 1;

    e = e->p;
    e1 = e1->p;
  }

  return 1;
}

bool Address::eq(Address *addr){
  return cmp(addr) == 1;
}

bool Address::neq(Address *addr){
  return cmp(addr) != 1;
}

bool Address::lt(Address *addr){
  return cmp(addr) == 0;
}

bool Address::lte(Address *addr){
  return cmp(addr) != 2;
}

bool Address::gt(Address *addr){
  return cmp(addr) == 2;
}

bool Address::gte(Address *addr){
  return cmp(addr) != 0;
}

Address *Address::shl(u8 n){
  while(n--){
    Elem *e = arr->getHead();
    u8 b = 0;

    while(e){
      u8 val = (e->v << 1) | b;
      b = e->v & HIGHEST_BIT ? 1 : 0;
      e->v = val & INT_MASK;
      e = e->n;
    }

    if(b) arr->push(1);
  }

  return this;
}

Address *Address::shr(u8 n){
  while(n--){
    Elem *e = arr->getTail();
    u8 bit = 0;

    while(e){
      u8 val = (e->v >> 1) | (bit ? HIGHEST_BIT : 0);
      bit = e->v & 1;
      e->v = val;
      e = e->p;
    }
  }

  return this;
}

Address *Address::inc(){
  Elem *e = arr->getHead();
  u8 bit = 1;

  while(e){
    u8 val = e->v + bit;
    bit = val > INT_MASK ? 1 : 0;
    e->v = val & INT_MASK;

    if(!bit) break;
    e = e->n;
  }

  if(bit) arr->push(1);
  return this;
}

Address *Address::dec(){
  Elem *e = arr->getHead();
  u8 bit = 1;

  while(e){
    u8 val = e->v - bit;
    bit = val < 0 ? 1 : 0;
    e->v = val & INT_MASK;

    if(!bit) break;
    e = e->n;
  }

  return this;
}

Address *Address::add(Address *addr){
  return this;
}

Address *Address::sub(Address *addr){
  return this;
}

u8 Address::valueOf(){
  Elem *e = arr->getTail();
  u8 val = 0;

  while(e){
    val = (val << INT_SIZE) | e->v;
    e = e->p;
  }

  return val;
}