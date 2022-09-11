#pragma once
#include <iostream>
#include <new>
class PriorityQueue
{
public:
    PriorityQueue(const PriorityQueue&) = default;
    PriorityQueue(PriorityQueue&&) = default;
    PriorityQueue& operator=(const PriorityQueue&) = default;
    PriorityQueue& operator=(PriorityQueue&&) = default;

    PriorityQueue() { size_ = 0; }
    ~PriorityQueue();

    void Push(int item, int priority);
    int Pop();
    int GetAt(size_t index);
    size_t Size();
    void Clear();
    void Print(const char* objName);

private:
    int* elements_;
    int* priorities_;
    size_t size_;
};

    //void main()
//{
//    QueueP<int> Q1;
//    QueueP<int> Q2 = Q1;

//    Q1.Push(15, 7);
//    Q1.Push(18, 9);
//    Q1.Push(18, 9);
//    Q1.Push(18, 9);
//    Q1.Push(1, 3);
//    Q1.Push(8, 6);
//    Q1.Push(11, 6);
//    Q1.Push(4, 6);
//    Q1.Print("Q1");

//    int d;
//    d = Q1.Pop();
//    d = Q1.Pop();
//    d = Q1.Pop();
//    d = Q1.Pop();
//    Q1.Print("Q1");
//    cout << "d = " << d << endl;

//    QueueP<int> Q3 = Q1; // конструктор копирования
//    Q3.Print("Q3");

//    QueueP<int> Q4;
//    Q4 = Q3 = Q1; // оператор присваивания копированием
//    Q4.Print("Q4");

//    cout << "count = " << Q4.Count() << endl;
//    Q4.Clear();
//    Q4.Print("Q4");
//    cout << "count = " << Q4.Count() << endl;
//}

