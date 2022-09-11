#include <cassert>
#include "PriorityQueue.h"

template<typename T>
void PriorityQueue<T>::SortInsert(T item,int priopity)
{
    Node<T>* newNode = new Node<T>(item,priopity);

    if (size == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        for (Node<T>* current = tail; current ; current = current->prev)
        {
            if (priopity > current->priopity && current->prev != nullptr)
            {
                if (current == tail)
                {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                    tail->next = nullptr;
                }
                else
                {
                    newNode->prev = current;
                    newNode->next = current->next;
                    current->next->prev = newNode;
                    current->next = newNode;
                }
                break;
            }
            else if (current->prev == nullptr)
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                break;
            }
        }
    }
    ++size;
}

template<typename T>
void PriorityQueue<T>::Print()
{
    for (Node<T>* current = head; current != tail->next; current = current->next)
    {
        std::cout << current->data << ":"<<current->priopity<<" ";
    }
    std::cout << std::endl;
}

template<typename T>
T PriorityQueue<T>::PopHead()
{
    // assert(head != nullptr); // так всё-таки можно
    // assert(head != nullptr && "Priority queue is empty"); // так можно выводить с сообщением
    // static_assert(head != nullptr, "Priority queue is empty"); // вызывается во время компиляции, а не во время выполнения
    if (head == nullptr)
    {
        //return T();
        assert(false);
    }
    Node<T> *newNode = head->next;
    T temp = head->data;
    delete head;
    head = newNode;
    --size;
    return temp;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    while (head)
    {
        PopHead();
    }
}