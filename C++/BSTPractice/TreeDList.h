//
// Created by Victor on 29.03.2021.
//

#ifndef BINARY_SEARCH_TREE__TREEDLIST_H_
#define BINARY_SEARCH_TREE__TREEDLIST_H_
#include <iostream>
#include "Tree.h"
template<class T>
class TreeDlist: public Tree<T> {
 public:
  TreeDlist():root_(0){};
  ~TreeDlist()override{
    Node::DestroyNode(root_);
  }

  void Insert(T key) override{
    Insert(root_,key);
  };
  bool Searcch(T key)override{
    if(Search(root_,key)){
      return true;
    }
    return false;
  };
  void Print()override{
    Print(root_);
  };


 private:
  struct Node {
   public:
    Node(int key):key_(key){};

    static void DestroyNode(Node*& node) {
      if (node) {
        DestroyNode(node->left_);
        DestroyNode(node->right_);
        delete node;
      }
    }

    T key_;
    Node* left_= nullptr;
    Node* right_= nullptr;
  };


  void Insert(Node*& node,T key) {
    if (!node) {
      node = new Node(key);
    } else if (key < node->key_) {
      Insert(node->left_, key);
    } else if (key > node->key_) {
      Insert(node->right_, key);
    } else //key==root->key_)
      return;
  }

    void Print(Node* node) {
      if (node == nullptr) {
        return;
      }
      Print(node->left_);
      std::cout << node->key_ << " ";
      Print(node->right_);
    }


    Node* Search(Node* node,T key) {
      if (node->key_ == key) {
        return node;
      } else if (key < node->key_) {
        return Search(node->left_, key);
      } else {
        return Search(node->right_, key);
      }
    }


  Node* root_;
};

#endif //BINARY_SEARCH_TREE__TREEDLIST_H_
