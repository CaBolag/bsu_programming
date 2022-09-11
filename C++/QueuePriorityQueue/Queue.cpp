#include "Queue.h"

/*
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
////    for (Queue<T>::Node* current = head; current != tail->next; current = current->next)
////    {
////        std::cout << current->data << " ";
////    }
////    std::cout << std::endl;
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
    if (size == 0)
    {
        std::cout << "List is empty" << std::endl;
        return T();
    }

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
}*/
