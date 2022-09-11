//
// Created by Victor on 27.03.2021.
//

#ifndef BINARY_SEARCH_TREE__TREE_H_
#define BINARY_SEARCH_TREE__TREE_H_

template<class T>
class Tree {
 public:
  virtual ~Tree();
  virtual void Insert(T key);
  virtual bool Search(T key);
  virtual void Print();

};
#endif //BINARY_SEARCH_TREE__TREE_H_
