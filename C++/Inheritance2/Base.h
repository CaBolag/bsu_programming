//
// Created by Victor on 11.12.2020.
//

#ifndef INHERITANCE_VAR_1__BASE_H_
#define INHERITANCE_VAR_1__BASE_H_
#include <string>
#include<vector>
#include<algorithm>
#include <iostream>
#include<iterator>
#include<sstream>

using std::ostream;
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Base_sweet
{
 public:
  Base_sweet();
  virtual ~Base_sweet();//virtual-метод, значит, что метод
  //будет переопределен в производном классе, а если нет, то
  //будет взят из базового класса
  virtual std::ostream & print();
  virtual void read(std::istringstream &);
  double get_sugar()const { return sugar; }
  double get_weight()const { return weight; }
  double get_price()const { return price; }
  bool operator ==(double _sugar) { return this->sugar == _sugar; }
  friend ostream & operator<<(ostream &, Base_sweet* &);

 private:
  string name;
  double weight;
  double sugar;
  double price;

};

Base_sweet::Base_sweet()
{
}

Base_sweet::~Base_sweet()
{
}

std::ostream & Base_sweet::print()
{
  cout << "name: " << name << " | " << "weight: " << weight << " | " << "sugar: " << sugar << " | " << "price: " << price;
  return cout;
}

void Base_sweet::read(std::istringstream & in)
{
  in >> name >> weight >> sugar >> price;
}
ostream & operator<<(ostream & out, Base_sweet* & sweet)
{
  (*sweet).print();
  return out;
}
#endif //INHERITANCE_VAR_1__BASE_H_
