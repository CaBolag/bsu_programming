#include "PriorityQueue.h"

PriorityQueue::~PriorityQueue() {
    if (size_ > 0){
        delete[] elements_;
        delete[] priorities_;
    }
}
void PriorityQueue::Push(int item, int priority)
{
    int* new_elements = new int[size_ + 1];
    int* new_priorities = new int[size_ + 1];

    int pos;

    if (size_ == 0)
        pos = 0;
    else
    {
        pos = 0;
        while (pos < size_){
            if (priorities_[pos] < priority) break;
            pos++;
        }
    }

    // 3. Копирование данных A2<=A; P2<=P
    // по формуле P = [0,1,...] + pos+1 + [pos+2,pos+3,...]
    // 3.1. Индексы массива с номерами 0..pos
    for (int i = 0; i < pos; i++){
        new_elements[i] = elements_[i];
        new_priorities[i] = priorities_[i];
    }


    new_elements[pos] = item;
    new_priorities[pos] = priority;

    for (int i = pos + 1; i < size_ + 1; i++){
        new_elements[i] = elements_[i - 1];
        new_priorities[i] = priorities_[i - 1];
    }

    if (size_ > 0){
        delete[] elements_;
        delete[] priorities_;
    }
    elements_ = new_elements;
    priorities_ = new_priorities;
    size_++;
}


int PriorityQueue::Pop()
{
    if (size_ == 0)
        return 0;

    int* new_elements = new int[size_ - 1]; // на 1 элемент меньше
    int* new_priorities = new int[size_ - 1];
  
    int item;
    item = elements_[0];

    for (int i = 0; i < size_ - 1; i++){
        new_elements[i] = elements_[i + 1];
        new_priorities[i] = priorities_[i + 1];
    }

    if (size_ > 0){
        delete[] elements_;
        delete[] priorities_;
    }

    size_--;
    elements_ = new_elements;
    priorities_ = new_priorities;

    return item;
}

size_t PriorityQueue::Size() {
    return size_;
}

int PriorityQueue::GetAt(size_t index) {
    return elements_[index];
}

void PriorityQueue::Clear() {
    if (size_ > 0){
        delete[] elements_;
        delete[] priorities_;
    }
}


void PriorityQueue::Print(const char* objName)
{
    std::cout << "Object: " << objName << std::endl;
    for (int i = 0; i < size_; i++)
        std::cout << elements_[i] << ":" << priorities_[i] << "\t" << std::endl;
    std::cout << std::endl;
    std::cout << "---------------" << std::endl;
}