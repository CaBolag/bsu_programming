//
// Created by Victor on 04.04.2021.
//

#ifndef BINARY_SEARCH_TREE__TREEARRAY_H_
#define BINARY_SEARCH_TREE__TREEARRAY_H_
#include <iostream>
#include "Tree.h"
template<typename T>
class TreeArray:Tree<T> {
 public:
  TreeArray(size_t size){
    tree_=new T(size);
    size_=size;
    for (int kI = 0; kI < size; ++kI) {
      tree_[kI]= 0;
    }
  }
  ~TreeArray()override{
    delete[] tree_;
  }

  void Insert(T key) override{
    static size_t count;
    if(tree_== nullptr){
      T tree[size_+1];
      for(size_t i=0;i<count;i++){
        tree[i]=tree_[i];
      }
      tree[count]=key;
      for(size_t i=count+1;i<size_;i++){
        tree[i]=tree_[i];
      }
    }
    else if(*tree_==0){
      tree_[count]=key;
    }
    else if(key<*tree_){
      count++;
      tree_++;
      Insert(key);
    }
    else if(key>*tree_) {
      count++;
      tree_++;
      tree_++;
      Insert(key);
    }
    else //key==root->key_)
      return;
  };

  bool Search(T key)override{
    for(size_t i=0;i<size_;i++){
      if(tree_[i]==key){
        return true;
      }
    }
    return false;
  };

  void Print()override{
    int i=0;
    int branches=0;
    while(i<size_){
      i=2*i+1;
      branches++;
    }
    int branches_=branches;
    while(branches!=0){
      std::cout<<tree_[2*branches+2];
      branches--;
    }
    std::cout<<tree_[0];
    while(branches_!=0){
      std::cout<<tree_[2*branches+1];
      branches--;
    }
  };

   private:
   size_t size_;
   T* tree_;
};

#endif //BINARY_SEARCH_TREE__TREEARRAY_H_
