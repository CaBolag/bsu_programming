//
// Created by Victor on 22.11.2020.
//

#include "StackOnList.h"

/*template<typename T>
StackOnList<T>::StackOnList(const StackOnList<T>& stackOnList):size(stackOnList.size){
   // assert(stackOnList.size=0 && StackOnList());

   if(stackOnList.size==0){
       StackOnList();
       return;
   }

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
    //копирование элементов из старого объекта
    NodeStack<T>* element=new NodeStack<T>(stackOnList.top->value, nullptr);
    top=element;
    NodeStack<T>* cur_element=stackOnList.top->next;
    while (cur_element != nullptr) {
        element->next = new NodeStack<T>(cur_element->value, nullptr);
        element = element->next;
        cur_element = cur_element->next;
    }


    //удаление старого объекта
    while(stackOnList.top!= nullptr){
        NodeStack<T> *temp=stackOnList.top;
        stackOnList.top=stackOnList.top->next;
        delete temp;
    }
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
StackOnList<T>& StackOnList<T>:: operator=( StackOnList&& stackOnList){
    if(this==&stackOnList){

        //удаление старого объекта
        while(stackOnList.top!= nullptr) {
            NodeStack<T> *temp = stackOnList.top;
            stackOnList.top = stackOnList.top->next;
            delete temp;
        }
        stackOnList.size=0;
        return *this;
    }

    //освобождение памяти объекта для записи новых данных из другого объекта
    while(top!= nullptr){
        NodeStack<T> *temp=top;
        top=top->next;
        delete temp;
    }

    size=stackOnList.size;

    if(size==0){
        top= nullptr;
        //удаление старого объекта
        while(stackOnList.top!= nullptr) {
            NodeStack<T> *temp = stackOnList.top;
            stackOnList.top = stackOnList.top->next;
            delete temp;
        }
        stackOnList.size=0;
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

    //удаление старого объекта
    while(stackOnList.top!= nullptr) {
        NodeStack<T> *temp = stackOnList.top;
        stackOnList.top = stackOnList.top->next;
        delete temp;
    }
    stackOnList.size=0;
    return *this;
}


template <typename T>
StackOnList<T>::StackOnList(std::initializer_list<T>& list):StackOnList(){
    *//*size=list.size();*//*
    for(T value:list){
        Push(value);
        *//*NodeStack<T>* newElement=new NodeStack<T>(value,top);
        top=newElement;*//*
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
}*/
//int StackOnList::size();