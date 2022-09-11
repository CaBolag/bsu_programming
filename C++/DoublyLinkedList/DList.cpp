#include "DList.h"
template<class Type>
std::ostream& operator <<(std::ostream& out, DList<Type>& l){
    for (DList<int>::Iterator i = l.begin();i!=l.end(); i++) {
        std::cout<<*i<<" ";
    }
    return out;
}


template <class T>
DList<T>::~DList<T>(){
    while(size>0){
        pop_back();
    }
}

template<typename T>
DList<T>::DList(const DList<T> &list){
  size = 0;
  Node *cur = list.head;
  while (cur != nullptr) {
    Push(cur->data);
    cur = cur->next;
  }
}

template<class T>
void DList<T>::push_back(const T & value) {
    Node* newNode=new Node(value,tail);
    if(size==0){
        head= nullptr;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
    size++;
}


template<class T>
void DList<T>::push_front(const T & value) {
    Node* newNode=new Node(value, nullptr,head);
    if(size==0){
        tail= nullptr;
    }
    else{
        head->prev=newNode;
    }
    head=newNode;
    size++;
}


template<typename T>
void DList<T>:: insert(const T& temp_data, size_t index)
{
    if (index > size)
    {
        std::cout << "Error index! Insert cannot be done!\n";
        return;
    }

    if (index == 0)
    {
        push_front(temp_data);
        return;
    }

    if (index == size)
    {
        push_back(temp_data);
        return;
    }

    Node* pos = head;
    size_t count = 0;

    while (count != index) //поиск нужной позиции
    {
        pos = pos->next;
        count++;
    }

    Node* temp = new Node(temp_data, pos->prev, pos);
    (pos->prev)->next = temp;
    pos->prev = temp;
    size++;
}

template<typename T>
void DList<T>::insert(const T &temp_data, size_t index, size_t numOfElements) {
  for(int i=0;i<numOfElements;++i){
    insert(temp_data,index+i);
  }
}

template<class T>
T DList<T>::pop_back() {

    if(size=0){
        std::cout<<"List is empty"<<std::endl;
        return T();
    }
    Node* temp=tail;
    T key=temp->data;
    tail=tail->prev;
    delete temp;
    if(size==1){
        head= nullptr;
    }
    size--;
    return key;

}


template<class T>
T DList<T>::pop_front()
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
}

template<typename T>
T DList<T>::erase(size_t index) {
  T temp=this[index];
  Node *cur=this->head;
  for(int i=0;i<index;i++){
    cur=cur->next;
  }
  cur->prev.next=cur->next;
  cur->next.prev=cur->next;
  return temp;
}

template<typename T>
void DList<T>::replace(const T & elem, const T &replace) {
  Node *cur = head;
  while (cur != nullptr) {
    if(cur->data==elem){
      cur->data=replace;
    }
    cur = cur->next;
  }
}

template<class T>
T& DList<T>::operator[](size_t index)
{
    if (index >= size)
    {
        std::cout << "Wrong index.\n";
        exit(0);
    }
    Node* cur = head;
    for (size_t i = 0; i < index; i++, cur = cur->next);

    return cur->data;
}

template<class T>
T& DList<T>::operator[](size_t index) const
{
  if (index >= size)
  {
    std::cout << "Wrong index.\n";
    exit(0);
  }
  Node* cur = head;
  for (size_t i = 0; i < index; i++, cur = cur->next);

  return cur->data;
}

template<typename T>
void DList<T>::erase(Iterator start, Iterator end) {
  for(DList<T>::Iterator i=start;i!=end;i++){
    delete *i;
  }
}

template<typename T>
int DList<T>::find(const T & value) {
  Node *cur=this->head;
  for(int i=0;i<size;i++) {
    if (cur->data = value) {
      return (i + 1);
    }
    cur = cur->next;
  }
  throw std::exception();
}
