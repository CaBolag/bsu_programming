//
// Created by Victor on 11.04.2021.
//

#ifndef ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAY_H_
#define ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAY_H_
#include<iostream>
#include "Iterator.h"


template<typename T>
class Array {

 public:
  Array() :size_(0), data_(nullptr) {};
  ~Array() { delete[] data_; }
  Array(const Array &a);
  Array(Array&&a);
  Array& operator=(const Array &a);
  Array& operator=(Array &&a);


  T& operator[](size_t index);
  T Get (int index) const;
  size_t GetSize() const { return this->size_; }
  void Add(T elem);
  void InsertAt(T elem,int index);
  void RemoveAt(int index);


  class ArrayIterator:public Iterator<T> {
   public:
    explicit ArrayIterator(const Array<T>* arr):array_(arr),current_(0){};
    virtual void First(){
      current_=0;
    }
    void Next()override{
      current_++;
    }
    bool IsDone() const override{
      return (current_>=array_->size_);
    }
    T CurrentItem() const override{
      if (IsDone()) {
        return '\0';
      }
      return array_->data_[current_];
    }

   private:
    const Array<T>* array_;
    size_t current_;
  };

  void PrintAll(ArrayIterator& start);

 /* ArrayIterator* CreateIterator() const {
    return new ArrayIterator(this);
  }*/

 private:
  size_t size_;
  T* data_;
};


template<typename T>
Array<T>::Array(const Array<T> &a) {
  for (size_t i = 0; i < a.size_; i++)
  {
    data_[i] = a.data_[i];
  }
}


template<typename T>
Array<T>::Array(Array<T> &&a):size_(a.size_),data_(a.data_) {
  a.size_ = 0;
  a.data_ = nullptr;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array<T> &a) {
  if (this != &a) {
    delete[]data_;
    size_ = a.size_;
    data_ = new int[size_];
    for (size_t i = 0; i < a.size_; i++)
    {
      data_[i] = a.data_[i];
    }
  }
  return *this;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> &&a) {
  if (this != &a) {
    delete[]data_;
    size_ = a.size_;
    data_ = a.data;
    a.Size = 0;
    a.data = nullptr;
  }
  return *this;
}


template<typename T>
T& Array<T>::operator[](size_t index) {
  if(index>=this->size_)
  {
    std::cout << "error index\n";
    exit(1);
  }
  return this->data_[index];
}

template<typename T>
T Array<T>::Get(int index) const {
  return this->data_[index];
}

template<typename T>
void Array<T>::Add(T elem) {

  int new_size=size_+1;
  T* new_arr=new T[new_size];
  for(size_t i=0;i<size_;i++){
    new_arr[i]=data_[i];
  }
  new_arr[size_]=elem;
  delete[] data_;
  data_=new_arr;
  size_=new_size;
}

template<typename T>
void Array<T>::InsertAt(T elem, int index) {
  int new_size=size_+1;
  T* new_arr=new T[new_size];
  for(int i=0;i<index;i++){
    new_arr[i]=data_[i];
  }
  new_arr[index]=elem;
  for (int i = index+1; i < new_size; ++i) {
    new_arr[i]=data_[i-1];
  }
  delete [] data_;
  data_=new_arr;
  size_=new_size;
}

template<typename T>
void Array<T>::RemoveAt(int index) {

  int new_size=size_-1;
  T *new_arr=new T[new_size];
  for(int i=0;i<index;i++){
    new_arr[i]=data_[i];
  }
  for (int i = index+1; i < new_size; ++i) {
    new_arr[i-1]=data_[i];
  }
  delete[] data_;
  data_=new_arr;
}

template<typename T>
void Array<T>::PrintAll(ArrayIterator& start) {
  for(start.First(); !start.IsDone(); start.Next()) {
    std::cout<<start.CurrentItem();
  }
}

#endif //ONE_DEMENTIONAL_ARRARY_WITH_ITERATOR__ARRAY_H_
