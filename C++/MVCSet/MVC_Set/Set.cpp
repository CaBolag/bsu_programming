#include "Set.h"

std::ostream& operator <<(std::ostream& out, const Set& set) {
    for (int i = 0; i < set.Size(); i++) {
        out << set[i] << " ";
    }
    out << "\n";
    return out;
}


std::ifstream& operator >>(std::ifstream& in, Set& set) {
   /*  std::vector<int >elements;
     std::copy(std::istream_iterator<int>(in), std::istream_iterator<int>(), std::back_inserter(elements));
     Set new_set(elements);
     set=std::move(new_set);
    return in;*/
}

Set::~Set() {
    delete[] data_;
    size_ = 0;
}

Set::Set(const Set& set) :size_{ set.size_ }, data_{ new int[set.size_] } {
    std::uninitialized_copy(set.data_, set.data_ + set.size_, data_);

}

Set::Set(Set&& set) : size_{ set.size_ }, data_{ set.data_ } {
    set.size_ = 0;
    set.data_ = nullptr;
}

Set::Set(const std::initializer_list<int>& elements) {
    data_ = new int[elements.size()];
    std::copy(elements.begin(), elements.begin() + elements.size(), data_);
    size_ = elements.size();
}

Set::Set(const std::vector<int>& elements) {
    data_ = new int[elements.size()];
    std::copy(elements.begin(), elements.begin() + elements.size(), data_);
    size_ = elements.size();
}

Set& Set::operator=(const Set& set) {
    if (this->size_ != set.size_) {
        throw std::runtime_error("(oparator=) unequal size");
    }
    std::copy(set.data_, set.data_ + set.size_, data_);
    return *this;
    /* Set tmp {set};
     std::swap(tmp,*this);
     return *this;*/
}

Set& Set::operator=(Set&& set) {
    std::swap(data_, set.data_);
    std::swap(size_, set.size_);
    return *this;
}

int Set::operator[] (size_t index) const {
    if (index >= this->size_)
    {
        throw std::runtime_error("(operator[]) index is too large");
    }
    return this->data_[index];
}


Set Set::operator+(const Set& set) {
    Set union_set{ *this };
    SetIterator iterator1(union_set);
    SetIterator iterator2(set);
    bool flag = true;
    for (iterator2.First(); !iterator2.IsDone(); iterator2.Next()) {
        for (iterator1.First(); !iterator1.IsDone(); iterator1.Next()) {
            if (iterator2.CurrentItem() == iterator1.CurrentItem()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            union_set.data_[union_set.size_] = iterator2.CurrentItem();
            union_set.size_++;
        }
        flag = true;
    }
    return (union_set);
}

Set& Set::operator+=(const Set& set) {
    *this = *this + set;
    return *this;
}

Set Set::operator*(const Set& set) {
    Set intersection_set;
    SetIterator iterator1(*this);
    SetIterator iterator2(set);

    for (iterator2.First(); !iterator2.IsDone(); iterator2.Next()) {
        for (iterator1.First(); !iterator1.IsDone(); iterator1.Next()) {
            if (iterator2.CurrentItem() == iterator1.CurrentItem()) {
                intersection_set.data_[intersection_set.size_] = iterator2.CurrentItem();
                intersection_set.size_++;
                break;
            }
        }
    }
    return intersection_set;
}

Set& Set::operator*=(const Set& set) {
    *this = (*this) * set;
    return *this;
}

bool Set::operator==(const Set& set) {
    bool flag = true;
    if (size_ != set.size_) {
        return false;
    }
    for (int i = 0; i < size_; i++) {
        if (data_[i] != set[i]) {
            flag = false;
        }
    }
    return flag;
}

bool Set::operator!=(const Set& set) {
    return !(*this == set);
}

size_t Set::Size() const {
    return size_;
}
void Set::Clear() {
    if (size_ = 0) {
        throw std::runtime_error("(Clear()) set is empty");
    }
    delete[] data_;
    size_ = 0;
}

void Set::Swap(Set& set) {
    std::swap(*this, set);
}

void Set::Accept(Visitor& visitor) const {
    SetIterator iterator(*this);
    for (iterator.First(); !iterator.IsDone(); iterator.Next()) {
        visitor.VisitInt(iterator.CurrentItem());
    }
}