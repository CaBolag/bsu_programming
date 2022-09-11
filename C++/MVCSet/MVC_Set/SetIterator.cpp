#include "Set.h"
#include "SetIterator.h"


void SetIterator::First() {
    currentIndex_ = 0;
}

void SetIterator::Next() {
    currentIndex_++;
}

bool SetIterator::IsDone() const {
    return currentIndex_ >= set_.Size();
}

int SetIterator::CurrentItem() const {
    if (IsDone()) {
        throw std::out_of_range("Set::operator[]");
    }

    return set_[currentIndex_];

}