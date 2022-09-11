//
// Created by Victor on 04.12.2020.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <iostream>
template<class T>
class Heap{
private:
    size_t size;
    size_t memory_size;
    T* data;
public:
    Heap():size(0),memory_size(5),data(new T[memory_size]){};
    ~Heap(){delete[] data;};
    void Add(const T&);
    T* get_max;
    T* get_min;
    void Print () const;
    static const int grow=5;

};

template<class T>
void Heap<T>::Add(const T& value) {
    if(size>=memory_size){
       memory_size+=grow;
       T* temp=new T[memory_size];
       for(int i=0;i<size;i++){
           temp[i]=data[i];
       }
       delete[] data;
       data=temp;
    }
    data[size]=value;
    int index=size, parent_index=(index-1)/2;
//parent_index>=0 && index>0
    while(true){ //пока не дошли до корня дерева
        if(data[index]<=data[parent_index]){
            break;
        }
        if(data[index]>data[parent_index]){
            std::swap(data[index],data[parent_index]);
            index=parent_index;
            parent_index=(index-1)/2;
        }

    }
    size++;
}

template<class T>
void Heap<T>::Print ()const {
    for(int i=0;i<size;i++){
        std::cout<<data[i]<<" "<<std::endl;
    }
}
#endif //HEAP_HEAP_H
