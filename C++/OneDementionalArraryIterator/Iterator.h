//
// Created by Victor on 11.04.2021.
//

#ifndef ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATOR_H_
#define ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATOR_H_

template<typename T>
class Iterator {
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() const = 0;
  virtual T CurrentItem() const=0;
// protected:
//  Iterator();
};

#endif //ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ITERATOR_H_
