#pragma once

#include "main.h"
#include "elem.h"

class Array{
  Elem *head = nullptr;
  Elem *tail = nullptr;
  u8 len = 0;

public:
  Array();
  ~Array();

  Array *slice();
  void push(u8 v);
  void unshift(u8 v);
  u8 pop();
  u8 shift();
  u8 &first();
  u8 &last();
  Elem *getHead();
  Elem *getTail();
  u8 getLen();
  void setLen(u8 len);
};