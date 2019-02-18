#pragma once

#include "main.h"

struct Elem{
  u8 v;
  Elem *p, *n;

  Elem(u8 v, Elem *p=nullptr, Elem *n=nullptr);
  ~Elem();
};