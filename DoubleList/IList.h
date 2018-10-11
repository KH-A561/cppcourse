//
// Created by alexander on 11.10.18.
//

#ifndef DOUBLELIST_ILIST_H
#define DOUBLELIST_ILIST_H

#include "IIterator.h"
template<typename T>
class IList {
 public:
  //virtual ~IList() = 0;

  virtual void push(T& elem) = 0;
  virtual void remove() = 0;
  virtual IIterator<T>* listIterator(T elem) = 0;
  virtual void clear() = 0;
  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;
  virtual IIterator<T>* iterator() = 0;
  virtual void toString() = 0;
};

#endif //DOUBLELIST_ILIST_H
