#include "elem.h"

Elem::Elem(u8 v, Elem *p, Elem *n){
  this->v = v;
  this->p = p;
  this->n = n;
}

Elem::~Elem(){
  this->p = this->n = nullptr;
}