#ifndef WEEK_7_DYNAMIC_ARRAY_ARRAY_H
#define WEEK_7_DYNAMIC_ARRAY_ARRAY_H
#include<iostream>
class Array
{
public:
    Array() :size(0), data(nullptr) {};
    explicit Array(size_t _size);
    Array(const Array &a);
    //move constructor
    Array(Array&&a);
    Array& operator=(const Array &a);
    //move operator
    Array& operator=(Array &&a);
    int &operator[](size_t index);
    ~Array() { delete[]data; }
    size_t getsize() { return this->size; }
    void SetAt(int elem, size_t index);
    void Setsize(int size, int grow = 1);
    int GetUpperBound();
    bool IsEmpty();
    void FreeExtra();
    void RemoveAll();
    int GetAt(int index);
    void Add(int elem);
    void InsertAt(int elem,int index);
    void RemoveAt(int index);
    Array Append(Array arr);
private:
    size_t size;
    size_t index;
    int* data;
};
#endif //WEEK_7_DYNAMIC_ARRAY_ARRAY_H

