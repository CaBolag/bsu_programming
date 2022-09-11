#pragma once
#include<iostream>
#include<vector>
#include"BinaryTree.h"
#include "Iterator.h"

class BinaryTreeIterator :
	public Iterator
{
public:
	BinaryTreeIterator(const BinaryTree& binary_tree) :currentIndex_{ 0 }, elements_{binary_tree.ToVector()} { };
	void First() override;
	void Next() override;
	bool IsDone() const override;
	int CurrentItem() const override;

private:
    const std::vector<int> elements_;
	int currentIndex_;
};

