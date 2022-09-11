#include "BinaryTree.h"

BinaryTree::BinaryTree(size_t size) {
    data_ = new int(size);
    size_ = size;
    for (int kI = 0; kI < size; ++kI) {
        data_[kI] = 0;
    }
}


void BinaryTree::Insert(int new_element) {
    static size_t count;
    if (data_ == nullptr) {
        int* data = new int[size_ + 1];
        //int data[size_ + 1];
        for (size_t i = 0; i < count; i++) {
            data[i] = data_[i];
        }
        data_[count] = new_element;
        for (size_t i = count + 1; i < size_; i++) {
            data[i] = data_[i];
        }
    }
    else if (*data_ == 0) {
        data_[count] = new_element;
    }
    else if (new_element < *data_) {
        count++;
        data_++;
        Insert(new_element);
    }
    else if (new_element > * data_) {
        count++;
        data_++;
        data_++;
        Insert(new_element);
    }
    else //new_element==root->key_)
        return;
}


bool BinaryTree::Search(int element) const {
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == element) {
            return true;
        }
    }
    return false;
}


const std::vector<int> BinaryTree::ToVector() const
{
    std::vector<int> vector;
    int i = 0;
    int branches = 0;
    while (i < size_) {
        i = 2 * i + 1;
        branches++;
    }
    int branches_ = branches;
    while (branches != 0) {
        vector.push_back(data_[2 * branches + 2]);
        branches--;
    }
    vector.push_back(data_[0]);
    while (branches_ != 0) {
        vector.push_back(data_[2 * branches + 1]);
        branches--;
    }
    return vector;
}


void BinaryTree::Accept(Visitor& visitor) const {
    BinaryTreeIterator iterator(*this);
    for (iterator.First(); !iterator.IsDone(); iterator.Next()) {
        visitor.VisitInt(iterator.CurrentItem());
    }
}
