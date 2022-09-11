#include"Array.h"
Array::Array(size_t _size):size(_size),data(new int[size]){}
Array::Array(const Array &a):size(a.size), data(new int[size]),index(a.index)
{
    for (size_t i = 0; i < a.size; i++)
    {
        data[i] = a.data[i];
    }
}

Array& Array::operator=(const Array &a)
{
    if (this != &a) {
        delete[]data;
        size = a.size;
        index=a.index;
        data = new int[size];

        for (size_t i = 0; i < a.size; i++)
        {
            data[i] = a.data[i];
        }
    }
    return *this;
}

Array:: Array(Array&&a):size(a.size),data(a.data),index(a.index)
{
    a.size = 0;
    a.data = nullptr;
}

Array& Array::operator=(Array &&a)
{
    if (this != &a) {
        delete[]data;
        size = a.size;
        index=a.index;
        data = a.data;
        a.size = 0;
        a.data = nullptr;

    }
    return *this;
}

int & Array::operator[](size_t index)
{
    if(index>=this->size)
    {
        std::cout << "error index\n";
        exit(1);
    }
    return this->data[index];
}

void Array::Setsize(int size, int grow) {
  if (size > this->size) {
    int new_size=(size-this->size)*grow;
    int *new_arr=new int[new_size];
    for (int i = 0; i < this->size; i++) {
      new_arr[i] = this->data[i];
    }
    delete[]data;
    data=new_arr;
    size = new_size;
  }
  else if(size<this->size){
    int *new_arr=new int[size];
    for (int i = 0; i < size; i++) {
      new_arr[i] = this->data[i];
    }
    delete[]data;
    data=new_arr;
    size = size;
  }
}

int Array::GetUpperBound(){
  return data[index];
}

bool Array::IsEmpty(){
    if(this->data==nullptr){
        return true;
    }
    return false;
}

void Array::FreeExtra() {
  int *new_arr = new int[index+1];
  for(size_t i=0;i<index+1;i++){
    new_arr[i]=data[i];
  }
  delete [] data;
  data=new_arr;
  size=index+1;
}

void Array::RemoveAll() {
    delete [] data;
    size=0;
    index=-1;
}

int Array::GetAt(int index) {
    return this->data[index];
}

void Array::Add (int elem){

}

void Array::InsertAt(int elem,int index_){
    int new_size=size+1;
    int *new_arr=new int[new_size];
    for(int i=0;i<index_;i++){
        new_arr[i]=data[i];
    }
    new_arr[index_]=elem;
    for (int i = index_+1; i < new_size; ++i) {
        new_arr[i]=data[i-1];
    }
    delete [] data;
    data=new_arr;
    ++index;
}

void Array::RemoveAt(int index_) {
    int new_size=size-1;
    int *new_arr=new int[new_size];
    for(int i=0;i<index_;i++){
        new_arr[i]=data[i];
    }
    for (int i = index_+1; i < new_size; ++i) {
        new_arr[i-1]=data[i];
    }
    delete [] data;
    data=new_arr;
    --index;
}

Array Array::Append(Array arr){
    int new_size=size+arr.size;
    Array new_arr(new_size);
    for(int i=0;i<size;i++){
        new_arr[i]=data[i];
    }
    for(int i=0;i<arr.size;i++){
        new_arr[i+size]=arr.data[i];
    }
    index+=arr.index;
    return new_arr;
}

void Array::SetAt(int elem, size_t index)
{
    if (index >= this->size)
    {
        std::cout << "error index\n";
        exit(1);
    }
    this->data[index] = elem;

}