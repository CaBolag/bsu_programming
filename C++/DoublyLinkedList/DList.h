#ifndef WEEK_9_DOUBLY_LINKED_LIST_DLIST_H
#define WEEK_9_DOUBLY_LINKED_LIST_DLIST_H

#include <iostream>
template<class T>
class DList{
public:
    class Node{
    public:
        T data;
        Node* prev;
        Node* next;

        Node()=default;
        Node(const T& _data,Node* _prev= nullptr,Node* _next= nullptr):
        data(_data),prev(_prev),next(_next){};
        ~Node()=default;
    };

    DList():size(0),head(nullptr),tail(nullptr){};
    DList(const DList<T>& list);
    ~DList();
    void push_back(const T&);
    void push_front(const T&);
    void insert(const T&, size_t);
    void insert(const T&, size_t, size_t numOfElements);

    T pop_back();
    T pop_front();
    T erase(size_t);

    void replace(const T&, const T&);
    T& operator[](size_t);
    T& operator[](size_t) const;
    template<class Type>
    friend std::ostream& operator>>(std::ostream&, DList<T>&);
private:
    size_t size;
    Node* head;
    Node* tail;


public:
    class Iterator{
    public:
        Iterator()=default;
        Iterator(Node* _ptr):ptr(_ptr){};       ~Iterator()=default;
        //префиксная форма
        Iterator& operator++(){
            ptr=ptr->next;
            return *this;
        }
        //постфиксная форма
        Iterator& operator++(int){
            Iterator temp(*this);;//связали временный указатель с текущим объектом
            this->operator++();
            return temp;//возврат неизмененного объекта
        }

        Iterator& operator--(){
            ptr=ptr->prev;
            return *this;
        }

        Iterator& operator--(int){
            Iterator temp(*this);
            this->operator--();
            return *temp;
        }


        //оператор разыменования
        T& operator*()const{return ptr->data;}
        bool operator ==(const Iterator& i)const{return ptr==i.ptr;}
        bool operator !=(const Iterator& i)const{return ptr!=i.ptr;}
    private:
        Node* ptr;
    };


public:
  class Reverse_iterator{
    public:
    Reverse_iterator()=default;
    Reverse_iterator(Node* _ptr):ptr(_ptr){};
    ~Reverse_iterator()=default;
    //префиксная форма
    Reverse_iterator& operator++(){
      ptr=ptr->prev;
      return *this;
    }
    //постфиксная форма
    Reverse_iterator& operator++(int){
      Iterator temp(*this);;//связали временный указатель с текущим объектом
      this->operator++();
      return *temp;//возврат неизмененного объекта
    }

    Reverse_iterator& operator--(){
      ptr=ptr->next;
      return *this;
    }

    Reverse_iterator&  operator--(int){
      Iterator temp(*this);
      this->operator--();
      return *temp;
    }

    //оператор разыменования
    T& operator*()const{return ptr->data;}
    bool operator ==(const Iterator& i)const{return ptr==i.ptr;}
    bool operator !=(const Iterator& i)const{return ptr!=i.ptr;}
    private:
        Node* ptr;
    };

    Iterator begin(){return Iterator(head);}
    Iterator end(){return Iterator(tail->next);}
    Reverse_iterator Rbegin() { return Reverse_iterator(tail); }
    Reverse_iterator Rend() { return Reverse_iterator(head->prev); }

    void erase(Iterator start, Iterator end);
    int find(const T&);//номер заданного элемента

};

#endif //WEEK_9_DOUBLY_LINKED_LIST_DLIST_H
