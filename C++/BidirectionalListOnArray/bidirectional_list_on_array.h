

#ifndef KR_2_2020__BIDIRECTIONAL_LIST_ON_ARRAY_H_
#define KR_2_2020__BIDIRECTIONAL_LIST_ON_ARRAY_H__
#include <iostream>
#include <vector>
#include <initializer_list>
#include "word_card.h"
namespace containers {
template<typename T>
class BiDirectionalListOnArray {
 private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_;
  static const size_t MIN_CAPACITY = 10;
  static const size_t GROWTH_FACTOR = 2;

 public:
  BiDirectionalListOnArray() {
    data_ = new T[MIN_CAPACITY];
    capacity_=MIN_CAPACITY;
  };
  BiDirectionalListOnArray(std::initializer_list<T>);

  BiDirectionalListOnArray(const BiDirectionalListOnArray &);
  BiDirectionalListOnArray &operator=(const BiDirectionalListOnArray &);

  BiDirectionalListOnArray(BiDirectionalListOnArray &&);
  BiDirectionalListOnArray &operator=(BiDirectionalListOnArray &&);

  int Size() { return size_; }
  bool IsEmpty() { return (data_ == nullptr); };
  std::vector<T> ToVector();
  T *Front();
  T *Back();
  const T *Front() const;
  const T *Back() const;
  void PushFront(const T &value);
  void PushBack(const T &value);
  void PushFront(T &&value);
  void PushBack(T &&value);
  T PopFront();
  T PopBack();
  void InsertBefore(size_t index, const T &value);
  void InsertAfter(size_t index, const T &value);
  void InsertBefore(size_t index, T &&value);
  void InsertAfter(size_t index, T &&value);
  void Erase(size_t index);
  int Find(const T &value);
  std::vector<int> FindAll(const T &);

  T* operator[](size_t index);
  const T* operator[](size_t index)const;

  bool operator ==(const BiDirectionalListOnArray& list);
  bool operator !=(const BiDirectionalListOnArray& list);

};

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(std::initializer_list<T> list) {
  size_=list.size();
  if(list.size()<MIN_CAPACITY){
    size_=MIN_CAPACITY;
  }
  for (T value : list) {
    PushBack(value);
  }
  capacity_=size_+GROWTH_FACTOR;
}
template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(const BiDirectionalListOnArray<T> &array):
size_(array.size_),capacity_(array.capacity_) {
  for (size_t i = 0; i < array.size_; i++) {
    data_[i] = array.data_[i];
  }
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(BiDirectionalListOnArray<T> &&array)
    :size_(array.size_), data_(array.data_), capacity_(array.capacity_) {
  array.size_ = 0;
  array.data_ = nullptr;
}

template<typename T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(const BiDirectionalListOnArray<T> &array) {
  if (this != &array) {
    delete[]data_;
    size_ = array.size_;
    capacity_=array.capacity_;
    data_ = new int[size_];

    for (size_t i = 0; i < array.size_; i++) {
      data_[i] = array.data_[i];
    }
  }
  return *this;
}

template<typename T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(BiDirectionalListOnArray<T> &&array) {
  if (this != &array) {
    delete[]data_;
    size_ = array.size_;
    for (size_t i = 0; i < array.size_; i++) {
      data_[i] = array.data[i];
    }
    array.size_ = 0;
    array.data_ = nullptr;
  }
  return *this;
}

template<typename T>
std::vector<T> BiDirectionalListOnArray<T>::ToVector() {
  std::vector<T> result;
  for (int i = 0; i < size_; i++) {
    result.push_back(data_[i]);
  }
  return result;
}

template<typename T>
T* BiDirectionalListOnArray<T>::Front() {
  if(IsEmpty()){
    throw std::exception();
  }
  return data_;
}

template<typename T>
const T* BiDirectionalListOnArray<T>::Front() const {
  if(size_==0){
    throw std::exception();
  }
  return data_;//первый элемент
}

template<typename T>
T* BiDirectionalListOnArray<T>::Back() {
  if(IsEmpty()){
    throw std::exception();
  }
  return data_+size_;//последний элемент
}

template<typename T>
const T* BiDirectionalListOnArray<T>::Back()const {
  if(size_==0){
    throw std::exception();
  }
  return data_[size_ - 1];
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(const T &value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  new_arr[0] = value;
  for (int i = 1; i < new_size; i++) {
    new_arr[i] = data_[i - 1];
  }
  delete [] data_;
  data_ = new_arr;
  size_=new_size;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(const T &value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i < size_; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[new_size] = value;
  delete [] data_;
  data_ = new_arr;
  size_=new_size;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(T &&value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  new_arr[0] = (std::move(value));
  for (int i = 1; i < new_size; i++) {
    new_arr[i] = data_[i - 1];
  }
  delete [] data_;
  data_ = new_arr;
  size_=new_size;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(T &&value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i < size_; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[new_size] = (std::move(value));
  delete [] data_;
  size_=new_size;
  data_ = new_arr;
}

template<typename T>
T BiDirectionalListOnArray<T>::PopFront() {
  if(size_==0){
    throw std::exception();
  }
  size_t new_size = size_ - 1;
  T temp = data_[0];
  for (int i = 1; i < size_; i++) {
    data_[i - 1] = data_[i];
  }
  size_=new_size;
  return temp;
}

template<typename T>
T BiDirectionalListOnArray<T>::PopBack() {
  if(size_==0){
    throw std::exception();
  }

  size_t new_size = size_ - 1;
  T temp=data_[new_size];
  T *new_arr = new T[new_size];
  for (int i = 0; i < new_size; i++) {
    new_arr[i] = data_[i];
  }
  delete [] data_;
  data_=new_arr;
  size_=new_size;
  return temp;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, const T &value) {
  if (index == 0) {
    throw std::exception();
  }
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i < index; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[index] = value;
  for (size_t i = index + 1; i < new_size; ++i) {
    new_arr[i] = data_[i - 1];
  }
  delete[] data_;
  size_ = new_size;
  data_ = new_arr;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, const T &value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i <= index; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[index + 1] = value;
  for (size_t i = index + 2; i < new_size; ++i) {
    new_arr[i] = data_[i - 1];
  }
  delete[] data_;
  size_ = new_size;
  data_ = new_arr;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, T &&value) {
  if (index == 0) {
    throw std::exception();
  }
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i < index; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[index] = value;
  for (size_t i = index + 1; i < new_size; ++i) {
    new_arr[i] = data_[i - 1];
  }
  delete[] data_;
  size_ = new_size;
  data_ = new_arr;
  delete value;
}

template<typename T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, T &&value) {
  if(capacity_==size_){
    capacity_+=GROWTH_FACTOR;
  }
  size_t new_size = size_ + 1;
  T *new_arr = new T[new_size];
  for (int i = 0; i <= index; i++) {
    new_arr[i] = data_[i];
  }
  new_arr[index + 1] = value;
  for (size_t i = index + 2; i < new_size; ++i) {
    new_arr[i] = data_[i - 1];
  }
  delete[] data_;
  size_ = new_size;
  data_ = new_arr;
  delete value;
}

template<typename T>
void BiDirectionalListOnArray<T>::Erase(size_t index) {
  if(index>size_){
    throw std::exception();
  }
  size_t new_size = size_ - 1;
  int *new_arr = new T[new_size];
  for (int i = 0; i < index; i++) {
    new_arr[i] = data_[i];
  }
  for (size_t i = index + 1; i < new_size; ++i) {
    new_arr[i - 1] = data_[i];
  }
  delete[] data_;
  size_ = new_size;
  data_ = new_arr;
}

template<typename T>
int BiDirectionalListOnArray<T>::Find(const T &value) {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == value) {
      return i;
    }
  }
  return -1;
}

template<typename T>
std::vector<int> BiDirectionalListOnArray<T>::FindAll(const T &value) {
  std::vector<int> nums;
  if (IsEmpty()) {
    throw std::exception();
  }
  for (int i = 0; i < size_; i++) {
    if (data_[i] == value) {
      nums.push_back(i);
    }
  }
  return nums;
}

template<typename T>
T* BiDirectionalListOnArray<T>::operator[](size_t index) {
  if(index<0 or index>=size_){
    throw std::exception();
  }
  return *data_[index];
}

template <typename T>
const T* BiDirectionalListOnArray<T>::operator[](size_t index) const {
  if(index<0 or index>=size_){
    throw std::exception();
  }
  return *data_[index];
}


template<typename T>
bool BiDirectionalListOnArray<T>::operator==(const BiDirectionalListOnArray<T> &other) {
  if (other.size_ == size_) {
    for (int i = 0; i < size_; ++i) {
      if (data_[i] != other[i]) {
        return false;
      }
      return true;
    }
  } else {
    return false;
  }
}

template <typename T>
bool BiDirectionalListOnArray<T>::operator!=(const BiDirectionalListOnArray<T> &other) {
  if(this==other) {
    return false;
  }
  else{
    return true;
  }
}

}



#endif //KR_2_2020__BIDIRECTIONAL_LIST_ON_ARRAY_H_
