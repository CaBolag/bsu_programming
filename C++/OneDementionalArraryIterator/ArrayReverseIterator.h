//
// Created by Victor on 11.04.2021.
//

#ifndef ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAYREVERSEITERATOR_H_
#define ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAYREVERSEITERATOR_H_

#include "Iterator.h"
#include "Array.h"

template<typename T>
class ArrayReverseIterator:public Iterator<T> {
 public:

  explicit ArrayReverseIterator(const Array<T>* arr);
  void First() override;
  void Next() override;
  bool IsDone() const override;
  T CurrentItem() const override;
 private:
  const Array<T>* array_;
  size_t current_;
};

template<typename T>
ArrayReverseIterator<T>::ArrayReverseIterator(const Array<T>* arr):array_(arr),current_(0){}

template<typename T>
void ArrayReverseIterator<T>::First() {
  current_=array_->GetSize()-1;
}

template<typename T>
void ArrayReverseIterator<T>::Next() {
  current_--;
}

template<typename T>
bool ArrayReverseIterator<T>::IsDone() const {
  return (current_<0 || current_>=array_->GetSize());
}

template<typename T>
T ArrayReverseIterator<T>::CurrentItem() const {
  if (IsDone()) {
    throw std::invalid_argument("Error");
  }
  return array_->Get(current_);
}

#endif //ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAYREVERSEITERATOR_H_
