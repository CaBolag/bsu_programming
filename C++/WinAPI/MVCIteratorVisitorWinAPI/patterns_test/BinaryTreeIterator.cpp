#include "BinaryTreeIterator.h"
void BinaryTreeIterator::First() {
    currentIndex_ = 0;
}

void BinaryTreeIterator::Next() {
    currentIndex_++;
}

bool BinaryTreeIterator::IsDone() const {
    return currentIndex_ >= elements_.size();
}

int BinaryTreeIterator::CurrentItem() const {
    return elements_.at(currentIndex_);

}


