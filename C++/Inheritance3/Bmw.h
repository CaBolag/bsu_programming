//
// Created by Victor on 17.12.2020.
//

#ifndef INHERITANCE_VAR_8__BMW_H_
#define INHERITANCE_VAR_8__BMW_H_

#include "Base_car.h"
class Bmw: public Base_car{
 public:
  Bmw(){};
  ~Bmw(){};
  std::ostream & print()override{Base_car::print();cout<<" | is_mini_cuper "<<is_mini_cuper;return cout;};
  void read(std::istringstream& in)override { Base_car::read(in);in>>is_mini_cuper;};
 private:
  bool is_mini_cuper;
};
#endif //INHERITANCE_VAR_8__BMW_H_
