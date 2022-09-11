//
// Created by Victor on 11.12.2020.
//

#ifndef INHERITANCE_VAR_1__COOKIES_H_
#define INHERITANCE_VAR_1__COOKIES_H_
#include "Base.h"

class Cookies :public Base_sweet
{
 public:
  Cookies();
  ~Cookies();
  std::ostream & print()override { Base_sweet::print(); cout << "form: " << form << " " << "filling: " << filling << "gluten: " <<gluten<< endl; return cout; }
  void read(std::istringstream & in)override { Base_sweet::read(in); in >> form >> filling>>gluten; }

 private:
  string form;
  string filling;//начинка
  bool gluten;

};

Cookies::Cookies()
{
}

Cookies::~Cookies()
{
}
#endif //INHERITANCE_VAR_1__COOKIES_H_
