#pragma once
#include<string>
#include"Visitor.h"
#include"BinaryTreeIterator.h"


class BinaryTree {
public:
    BinaryTree(size_t size);
    ~BinaryTree();


    BinaryTree(const BinaryTree&) = default;
    BinaryTree(BinaryTree&&) = default;
    BinaryTree& operator=(const BinaryTree&) = default;
    BinaryTree& operator=(BinaryTree&&) = default;

    void Insert(int new_element);
    bool Search(int element) const;
    const std::vector<int> ToVector() const;
    void Accept(Visitor& visitor) const;

private:
    size_t size_;
    int* data_;
};

