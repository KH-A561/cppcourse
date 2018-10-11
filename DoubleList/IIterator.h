//
// Created by alexander on 11.10.18.
//

#ifndef DOUBLELIST_IITERATOR_H
#define DOUBLELIST_IITERATOR_H

template<typename T>
class IIterator {
 public:
  virtual void start() = 0;
  virtual T get() = 0;
  virtual void next() = 0;
  virtual bool hasNext() = 0;
};

#endif //DOUBLELIST_IITERATOR_H
