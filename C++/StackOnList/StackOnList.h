//
// Created by Victor on 22.11.2020.
//

#ifndef PRACTICE_8_STACKONLIST_STACKONLIST_H
#define PRACTICE_8_STACKONLIST_STACKONLIST_H
#include "assert.h"
#include <initializer_list>
#include "NodeStack.h"
/* Задание 2.Создать класс для реализации Стека на последовательности связных компонент StackOnList и публичную структуру NodeStack.
Структура NodeStack должна содержать:
•	o Публичное поле value типа int со значением, хранимым в данном элементе списка.
•	o Приватные поля для осуществления связи элементов в списке.
•	o Приватный конструктор (ничто кроме StackOnList не должно иметь возможности создания элементов типа Node).

Класс StackOnList должны иметь следующий публичный интерфейс:
•	o Конструктор по умолчанию.
•	o Конструктор от std::initializer_list.
•	o Методы Size() и IsEmpty().
•	o Метод Push(const int& value), осуществляющий вставку элемента в вершину стека.
•	o Метод NodeStack* Top(), позволяющие получить первый элемент в стеке, не извлекая его.
•	o Метод int Pop(), осуществляющий извлечение первого элемента из стека и возвращающий его значение.
•	o Проверить корректность вызовов и передаваемых параметров с помощью assertов.
•	o Создать константный аналог для метода Top, который будет возвращать const NodeStack*.
•	o Обеспечить возможность проверки на равенство/различие стеков при помощи соответствующих операторов.
•	o Реализовать конструктор копирования и копирующий оператор присваивания.
•	o Реализовать конструктор перемещения и перемещающий оператор присваивания.*/
//Параметризовать класс из Задания 2.
template<class T>
class StackOnList{

public:

    StackOnList():size(0),top(nullptr){};
    StackOnList(const StackOnList& stackOnList);
    StackOnList(StackOnList&& stackOnList);
    StackOnList(std::initializer_list<T>& list);
    int Size(){return size;};
    bool IsEmpty(){return size==0;};
    void Push(const int& value);
    NodeStack<T>* Top(){return top;};
    NodeStack<T>* Top()const{return top;};
    T Pop();

    bool operator ==(const StackOnList& stackOnList);
    bool operator !=(const StackOnList& stackOnList);
    StackOnList& operator=(const StackOnList& stackOnList);
    StackOnList& operator=( StackOnList&& stackOnList);


private:
    int size;
    NodeStack<T>* top;
};


template<typename T>
StackOnList<T>::StackOnList(const StackOnList<T>& stackOnList):size(stackOnList.size){
     assert(stackOnList.size!=0 && "list is empty");
   /* if(stackOnList.size==0){
        StackOnList();
        return;
    }*/

    NodeStack<T>* element=new NodeStack<T>(stackOnList.top->value, nullptr);
    top=element;
    NodeStack<T>* cur_element=stackOnList.top->next;
    while (cur_element!= nullptr){
        element->next=new NodeStack<T>(cur_element->value, nullptr);
        element=element->next;
        cur_element=cur_element->next;
    }
}

template <typename T>
StackOnList<T>::StackOnList(StackOnList&& stackOnList):top(stackOnList.top),size(stackOnList.size){
  stackOnList.top= nullptr;
  stackOnList.size=0;
}

template <typename T>
StackOnList<T>& StackOnList<T>:: operator=(const StackOnList& stackOnList){
    //если объекты равны
    if(this==&stackOnList){
        return *this;
    }
    //освобождение памяти объекта для записи новых данных из другого объекта
    while(top!= nullptr){
        NodeStack<T>* temp=top;
        top=top->next;
        delete temp;
    }

    //если размер объекта, который мы копируем=0
    size=stackOnList.size;
    if(size==0){
        top= nullptr;
        return *this;
    }

    //копирование элементов
    NodeStack<T>* element=new NodeStack<T>(stackOnList.top->value, nullptr);
    top=element;
    NodeStack<T>* cur_element=stackOnList.top->next;
    while (cur_element!= nullptr){
        element->next=new NodeStack<T>(cur_element->value, nullptr);
        element=element->next;
        cur_element=cur_element->next;
    }
}

template<typename T>
StackOnList<T>& StackOnList<T>:: operator=( StackOnList&& stackOnList) {

  //освобождение памяти объекта для записи новых данных из другого объекта
  while (top != nullptr) {
    NodeStack<T> *temp = top;
    top = top->next;
    delete temp;
  }
  top=stackOnList.top;
  size=stackOnList.size;
  stackOnList.top= nullptr;
  stackOnList.size=0;
}


template <typename T>
StackOnList<T>::StackOnList(std::initializer_list<T>& list):StackOnList(){
    for(T value:list){
        Push(value);
    }
}

template <typename T>
void StackOnList<T>::Push(const int& value){
    NodeStack<T>* new_element=new NodeStack<T>(value, top);
    top=new_element;
    size++;
}
template <typename T>
T StackOnList<T>::Pop(){
    assert(size!=0 && "Stack is empty");
    NodeStack<T>* top_element=top;
    top=top->next;
    T value=top_element->value;
    delete top_element;
    --size;
    return value;
}

template<typename T>
bool StackOnList<T>::operator==(const StackOnList<T> &stackOnList) {
  if(size!=stackOnList.size){
    return false;
  }
  NodeStack<T> *elem1=top;
  NodeStack<T> *elem2=stackOnList.top;
  while(elem1!= nullptr){
    if(elem1->value!=elem2->value){
      return false;
    }
    elem1=elem1->next;
    elem2=elem2->next;
  }
  return true;
}

template<typename T>
bool StackOnList<T>::operator!=(const StackOnList<T> &stackOnList) {
  return !(this==stackOnList);
}
#endif //PRACTICE_8_STACKONLIST_STACKONLIST_H
