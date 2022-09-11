//
// Created by Victor on 04.02.2021.
//

#ifndef PRACTICE10__ROUTE_H_
#define PRACTICE10__ROUTE_H_
#include <iostream>
#include <vector>
using namespace std;

class Route{
 private:
  pair<int,string> bus_;
  string driver_name_;
  int route_number_;
 public:
  Route()=default;
  Route(pair<int,string> bus,string driver_name,int route_number):
  bus_(bus),driver_name_(driver_name),route_number_(route_number){};
  ~Route()=default;
  pair<int,string> get_bus() const {return bus_;}
  string get_driver_name()const {return driver_name_;}
  int get_route_number_() const{return route_number_;}
  void set_driver_name(string new_name){driver_name_=new_name;}
  void set_model(string new_model){bus_.second=new_model;}

};
#endif //PRACTICE10__ROUTE_H_
