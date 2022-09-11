//
// Created by Victor on 17.12.2020.
//

#ifndef INHERITANCE_VAR_8__MERCEDES_H_
#define INHERITANCE_VAR_8__MERCEDES_H_
#include "Base_car.h"
class Mercedes: public Base_car{
 public:
  Mercedes(){};
  ~Mercedes(){};
  std::ostream & print()override{Base_car::print();cout<<" | alloy_wheels: "<<alloy_wheels<<" | equipment: "<<equipment; return cout;};
  void read(std::istringstream& in)override { Base_car::read(in);in>>alloy_wheels>>equipment;};
 private:
  bool alloy_wheels;//литые диски
  string equipment;

};
#endif //INHERITANCE_VAR_8__MERCEDES_H_
