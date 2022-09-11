#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>
//#include "SumVisitor.h"
#include<vector>

//#include "Iterator.h"
#include "Visitor.h"
#include "SetIterator.h"

//class SetIterator;

class Set {

public:

    Set() : size_{ 0 }, data_{ new int[0] } {};
    ~Set();
    //explicit Set(size_t size);
    Set(const Set& set);
    Set(Set&& set);
    Set(const std::initializer_list<int>& elements);
    Set(const std::vector<int>& elements);
    Set& operator=(const Set& set);
    Set& operator=(Set&& set);
    int operator[](size_t index) const;
    Set operator+(const Set& set);
    Set& operator+=(const Set& set);
    Set operator*(const Set& set);
    Set& operator*=(const Set& set);
    bool operator ==(const Set& set);
    bool operator !=(const Set& set);
    int& GetAt(int index) const { return data_[index]; }

    size_t Size() const;
    void Clear();
    void Swap(Set& set);
    void SetSize(size_t size) { size_ = size; };
    void Accept(Visitor& visitor) const;

private:
    size_t size_;
    int* data_;
};

std::ostream& operator <<(std::ostream& out, const Set& set);
std::ifstream& operator >>(std::ifstream& in, Set& set);