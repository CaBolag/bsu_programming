#include <iostream>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Element.h"

void ReadInput(const std::string &filePath, Queue<Element> &queue);
Queue<Element> Conversion(Queue<Element> &queue);
void WriteCollection(const std::string &filePath, Queue<Element> &queue);

int main()
{
// {
// PriorityQueue<Element> queue;
// Element element1('P'), element2('R'), element3('I'), element4('O');
// queue.PopHead();
// queue.SortInsert(element1);
// queue.SortInsert(element2);
// queue.SortInsert(element3);
// queue.SortInsert(element4);
// queue.Print();
// queue.PopHead();
// queue.Print();
// }

    PriorityQueue<Element> queue;
    queue.SortInsert(1,5);
    queue.SortInsert(2,3);
    queue.SortInsert(3,4);
queue.Print();
    //ReadInput("C:\\Clion projects\\Guseinova\\KR_2_2019\\input.txt", queue);
// while (!queue.IsEmpty())
// {
// std::cout << queue.PopFront();
// }
// std::cout << std::endl;

    //Queue<Element> result = Conversion(queue);
    //WriteCollection("C:\\Clion projects\\Guseinova\\KR_2_2019\\output.txt", result);


    return 0;
}

void ReadInput(const std::string &filePath, Queue<Element> &queue)
{
    std::ifstream fin(filePath);
    if (!fin.is_open())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    char t;
    while (!fin.eof())
    {
        fin.get(t);
        queue.PushBack(Element(t));
    }
}

Queue<Element> Conversion(Queue<Element> &queue)
{
    PriorityQueue<Element> priorityQueue;
    Queue<Element> result;

    while (!queue.IsEmpty())
    {
        Element element = queue.PopFront();
        if (element.value == '*')
        {
            if (priorityQueue.GetSize() != 0)
            {
                result.PushBack(priorityQueue.PopHead());
            }
        }
        else
        {
            priorityQueue.SortInsert(element);
        }
    }
    return result;
}

void WriteCollection(const std::string &filePath, Queue<Element> &queue)
{
    std::ofstream fout(filePath);
    while (!queue.IsEmpty())
    {
        fout << queue.PopFront();
    }
    fout << std::endl;
}