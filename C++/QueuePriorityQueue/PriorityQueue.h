#pragma once

#ifndef KR2_2019_PRIORITYQUEUE_H
#define KR2_2019_PRIORITYQUEUE_H

#include <iostream>

template<typename T>
struct Node
{
    Node() = default;//конструктор по умолчанию
    Node(const T& _data,int _priopity=0, Node<T>* _prev = nullptr, Node<T>* _next = nullptr)
            : data(_data),priopity(_priopity), prev(_prev), next(_next) {};
    ~Node() = default;

    T data;
    Node<T>* prev;
    Node<T>* next;

    int priopity;
};

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue() : size(0), head(nullptr), tail(nullptr) {};
    ~PriorityQueue();

    void SortInsert(T item,int priority=0);
    T PopHead();
    void Print();
    size_t GetSize() const { return size; }

private:
    size_t size;
    Node<T>* head;
    Node<T>* tail;

};


#endif //KR2_2019_PRIORITYQUEUE_H