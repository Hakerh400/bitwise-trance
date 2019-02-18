#include "array.h"

Array::Array(){}

Array::~Array(){
  while(head) pop();
}

void Array::push(u8 v){
  if(!head){
    head = tail = new Elem(v);
  }else{
    tail->n = new Elem(v, tail);
    tail = tail->n;
  }

  len++;
}

void Array::unshift(u8 v){
  if(!head){
    head = tail = new Elem(v);
  }else{
    head->p = new Elem(v, nullptr, head);
    head = head->p;
  }

  len++;
}

u8 Array::pop(){
  u8 v = tail->v;
  
  if(head == tail){
    delete head;
    head = tail = nullptr;
  }else{
    tail = tail->p;
    delete tail->n;
    tail->n = nullptr;
  }

  len--;
  return v;
}

u8 Array::shift(){
  u8 v = head->v;

  if(head == tail){
    delete head;
    head = tail = nullptr;
  }else{
    head = head->n;
    delete head->p;
    head->p = nullptr;
  }

  len--;
  return v;
}

u8 Array::getLen(){
  return len;
}

void Array::setLen(u8 len){
  while(this->len != len)
    this->pop();
}