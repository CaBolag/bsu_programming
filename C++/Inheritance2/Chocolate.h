//
// Created by Victor on 11.12.2020.
//

#ifndef INHERITANCE_VAR_1__CHOCOLATE_H_
#define INHERITANCE_VAR_1__CHOCOLATE_H_
#include "Base.h"

class Chocolate :public Base_sweet
{
 public:
  Chocolate();
  ~Chocolate();
  std::ostream& print()override { Base_sweet::print(); cout << "cocoa: " << cocoa << " " << "filling: " << filling << endl; return cout; }
  void read(std::istringstream& in)override { Base_sweet::read(in); in >> cocoa >> filling; }

 private:
  double cocoa;
  string filling;//начинка

};

Chocolate::Chocolate()
{
}

Chocolate::~Chocolate()
{
}
#endif //INHERITANCE_VAR_1__CHOCOLATE_H_
