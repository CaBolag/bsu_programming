//
// Created by Victor on 17.12.2020.
//

#ifndef INHERITANCE_VAR_8__BASE_CAR_H_
#define INHERITANCE_VAR_8__BASE_CAR_H_
#include <iostream>
#include<sstream>
using std::ostream;
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Base_car{
 public:
  Base_car(){};
  virtual ~Base_car(){};
  virtual std::ostream & print();
  virtual void read(std::istringstream &);
  long long int get_serial_number()const{return serial_number;}
  double get_price() const{return price;}
  double get_fuel_consumption()const{return fuel_consumption;}
  int get_max_speed()const{return max_speed;}
  friend ostream & operator<<(ostream &, Base_car* &);

 private:
  string brand;
 long long int serial_number;
 double price;
 double fuel_consumption; //расход топлива
 int max_speed;
};

std::ostream & Base_car::print() {
  cout<<"brand: "<<brand<<" | serial_number: "<<serial_number<<" | price: "<<price<<
  " | fuel_consumption: "<<fuel_consumption<<" | max_speed: "<<max_speed;
  return cout;
}

void Base_car::read(std::istringstream &in) {
  in>>brand>>serial_number>>price>>fuel_consumption>>max_speed;
}
ostream & operator<<(ostream & out, Base_car* & car) {
  (*car).print();
  return out;
}
#endif //INHERITANCE_VAR_8__BASE_CAR_H_
