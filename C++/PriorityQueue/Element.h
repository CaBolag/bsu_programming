//
// Created by Victor on 04.12.2020.
//

#ifndef PRIORITY_QUEUE_ELEMENT_H
#define PRIORITY_QUEUE_ELEMENT_H
#include <iostream>
class Element
{
    char value;
public:
    Element() = default;
    Element(char value) : value(value) {};
    friend std::ostream& operator<<(std::ostream& out, const Element& e)
    {
        out << e.value;
        return out;
    }
};
#endif //PRIORITY_QUEUE_ELEMENT_H
