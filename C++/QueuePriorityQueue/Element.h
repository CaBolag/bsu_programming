#pragma once

#ifndef KR2_2019_ELEMENT_H
#define KR2_2019_ELEMENT_H


struct Element
{
    Element() = default;
    Element(char value) : value(value) {};
    // Должен совпадать с оператор в очереди с приоритетом
    bool operator>(const Element &element) const { return value < element.value; };
    friend std::ostream& operator<<(std::ostream &out, const Element &element) { out << element.value; return out; }
    char value;
};


#endif //KR2_2019_ELEMENT_H
