//
// Created by Victor on 29.11.2020.
//

#ifndef PRACTICE_8_STACKONLIST_NODESTACK_H
#define PRACTICE_8_STACKONLIST_NODESTACK_H
template<typename T>
struct NodeStack{
public:
    T value;
private:
    NodeStack* next;
    NodeStack()=default;
    NodeStack(T _value, NodeStack* _next):value(_value),next(_next){};

    template<typename Type>
    friend class StackOnList;
};

#endif //PRACTICE_8_STACKONLIST_NODESTACK_H
