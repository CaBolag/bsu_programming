#ifndef WEEK_6_CLASS_RATIONAL_H
#define WEEK_6_CLASS_RATIONAL_H
#include<iostream>
class Rational
{
private:
    int a, b;
    void reduce();
public:
    //конструктор по умолчанию
    Rational() = default;
    //конструктор с параметрами
    Rational(int a_, int b_);
    //конструктор копирования
    Rational(const Rational& r);
    //деструктор
    ~Rational() = default;
    Rational operator+(const Rational &r);
    Rational operator*(const Rational& r);
    Rational operator/(const Rational& r);
    friend long compare(const Rational& r, const Rational& r1);
    friend bool operator==(const Rational& r, const Rational& r1);
    friend bool operator<(const Rational& r, const Rational& r1);
    friend bool operator>(const Rational& r, const Rational& r1);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

};
#endif //WEEK_6_CLASS_RATIONAL_H
