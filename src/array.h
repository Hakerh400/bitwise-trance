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

  void push(u8 v);
  void unshift(u8 v);
  u8 pop();
  u8 shift();

  u8 getLen();
  void setLen(u8 len);
};