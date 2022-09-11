#include"X.h"
#include "XIterator.h"

void XIterator::First() {
    currentIndex_ = 0;
}

void XIterator::Next() {
    currentIndex_++;
}

bool XIterator::IsDone() const {
    return currentIndex_ >= x_.Size();
}

bool XIterator::CurrentItem() const {
    if (IsDone()) {
        throw std::out_of_range("Set::operator[]");
    }

    return x_.GetAt(currentIndex_);

}
