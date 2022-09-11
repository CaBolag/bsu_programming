//
// Created by Victor on 17.12.2020.
//

#ifndef INHERITANCE_VAR_8__AUDI_H_
#define INHERITANCE_VAR_8__AUDI_H_

#include "Base_car.h"
class Audi: public Base_car{
 public:
  Audi(){};
  ~Audi(){};
  std::ostream & print()override{Base_car::print();cout<<" | is_convertible "<<is_convertible;return cout;};
  void read(std::istringstream& in)override { Base_car::read(in);in>>is_convertible;};
 private:
  bool is_convertible;//с откидным верхом
};
#endif //INHERITANCE_VAR_8__AUDI_H_
