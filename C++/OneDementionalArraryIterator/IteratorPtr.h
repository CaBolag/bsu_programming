//
// Created by Victor on 11.04.2021.
//

#ifndef ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATORPTR_H_
#define ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATORPTR_H_
#include "Iterator.h"

template<typename T>
class IteratorPtr {
 public:
  IteratorPtr(Iterator<T>* iterator): iterator_(iterator) { }
  ~IteratorPtr() { delete iterator_; }
  Iterator<T>* operator->() { return iterator_; }
  Iterator<T>& operator*() { return *iterator_; }
 private:
// запретить копирование и присваивание, чтобы
// избежать многократных удалений _i
  IteratorPtr(const IteratorPtr&);
  IteratorPtr& operator=(const IteratorPtr&);
 private:
  Iterator<T>* iterator_;
};


#endif //ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATORPTR_H_
