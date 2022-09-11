//
// Created by Victor on 11.12.2020.
//

#ifndef INHERITANCE_VAR_1__LOLLY_POP_H_
#define INHERITANCE_VAR_1__LOLLY_POP_H_
#include "Base.h"

class Lolly_pop :public Base_sweet
{
 public:
  Lolly_pop();
  ~Lolly_pop();
  std::ostream & print()override { Base_sweet::print(); cout << "form: " << form << " " <<"taste: " <<taste << endl; return cout; }
  void read(std::istringstream & in)override { Base_sweet::read(in); in >> form >> taste; }

 private:
  string form;
  string taste;
};

Lolly_pop::Lolly_pop()
{
}

Lolly_pop::~Lolly_pop()
{
}
#endif //INHERITANCE_VAR_1__LOLLY_POP_H_
