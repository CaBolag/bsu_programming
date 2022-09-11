#pragma once

#ifndef DOUBLYLINKEDLIST_DLIST_H
#define DOUBLYLINKEDLIST_DLIST_H

#include <iostream>
#include <assert.h>

template<class T>
class Queue
{
public:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
        Node() = default;
        Node(const T& _data, Node* _previous = nullptr, Node* _next = nullptr) :
                data(_data), previous(_previous), next(_next) {}
        ~Node() = default;
    };

    Queue() : size(0), head(nullptr), tail(nullptr) {}
    ~Queue();

    void PushBack(const T& value);
    T PopBack();
    void PushFront(const T& value);
    T PopFront();

    bool IsEmpty() { return size == 0; };

private:
    size_t size;
    Node* head;
    Node* tail;

};

//template <class T>
//std::ostream& operator<<(std::ostream &out, Queue<T> &value);


template <class T>
Queue<T>::~Queue()
{
    while (size > 0)
    {
        PopBack();
    }
};

template<class T>
void Queue<T>::PushBack(const T &value)
{
    Node* newNode = new Node(value, tail);
    if (size == 0)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
    ++size;
}

//template<class T>
//std::ostream& operator<<(std::ostream &out, Queue<T> &list)
//{
//    for (Queue<T>::Node* current = head; current != tail->next; current = current->next)
//    {
//        std::cout << current->data << " ";
//    }
//    std::cout << std::endl;
//}

template<class T>
T Queue<T>::PopBack()
{
    if (size == 0)
    {
        std::cout << "List is empty" << std::endl;
        return T();
    }

    Node* temp = tail;
    T key = temp->data;
    tail = tail->previous;
    delete temp;
    if (size == 1)
    {
        head = nullptr;
    }
    size--;
    return key;
}

template<class T>
void Queue<T>::PushFront(const T &value)
{
    Node* newNode = new Node(value, nullptr, head);
    if (size == 0)
    {
        tail = newNode;
    }
    else
    {
        head->previous = newNode;
    }
    head = newNode;
    ++size;
}

template<class T>
T Queue<T>::PopFront()
{
    assert(size!=0 && "List is empty");
  /*  if (size == 0)
    {
        std::cout << "List is empty" << std::endl;
        return T();
    }*/

    Node* temp = head;
    T key = temp->data;
    head = head->next;
    delete temp;
    if (size == 1)
    {
        tail = nullptr;
    }
    size--;
    return key;
}
#endif //DOUBLYLINKEDLIST_DLIST_H