//
// Created by Victor on 17.12.2020.
//

#ifndef INHERITANCE_VAR_8__PROGRAM_H_
#define INHERITANCE_VAR_8__PROGRAM_H_
#include "vector"
#include <iterator>
#include <algorithm>
#include "Base_car.h"

class Program{
 public:
  Program();
  Program(std::vector<Base_car*>);
  ~Program(){};

  double price_park();
  void sort_consumption();
  std::vector<Base_car*> find_speed(int,int);
  void print_cars();
 private:
  std::vector<Base_car*> cars;
};

Program::Program(std::vector<Base_car *> cars_) {
  for(int i=0;i<cars_.size();++i){
    cars.push_back(cars_[i]);
  }
}

double Program::price_park() {
  double price;
  for(int i=0;i<cars.size();++i){
    Base_car* car=cars[i];
    price+=car->get_price();
  }
  return price;
}

void Program::sort_consumption() {
  std::sort(cars.begin(),cars.end(),[](Base_car* car1,Base_car* car2){
    return car1->get_fuel_consumption()>car2->get_fuel_consumption();
  });
}

std::vector<Base_car *> Program::find_speed(int speed1, int speed2) {
  std::vector<Base_car *> cars_with_speed;
  for(int i;i<cars.size();++i){
    Base_car* car=cars[i];
    if(car->get_max_speed()>=speed1 && car->get_max_speed()<=speed2){
      cars_with_speed.push_back(car);
    }
  }
  return cars_with_speed;
}

void Program::print_cars() {
  std::ostream_iterator<Base_car*&> out_cars(cout);
  copy(cars.begin(),cars.end(),out_cars);
}

#endif //INHERITANCE_VAR_8__PROGRAM_H_
