//
// Created by Victor on 04.02.2021.
//

#ifndef PRACTICE10__ROUTES_COLLECTION_H_
#define PRACTICE10__ROUTES_COLLECTION_H_
#include "Route.h"
#include <algorithm>
#include <set>
#include <map>
class RoutesCollections{
 private:
  vector<Route> routes_;
 public:
  RoutesCollections()=default;
  ~RoutesCollections()=default;
  void set_routes(vector<Route> routes){routes_=routes;};
  struct compareByBusNumber {
    bool operator()(const Route& a, const Route& b) {
      return a.get_bus() < b.get_bus();
    }
  };
  struct compareByDriverName {
    bool operator()(const Route& a, const Route& b) {
      return a.get_driver_name() < b.get_driver_name();
    }
  };

  void SortByBusNumber(){
    sort(routes_.begin(),routes_.end(),compareByBusNumber());
  }
  void SortByDriverName(){
    sort(routes_.begin(),routes_.end(),compareByDriverName());
  }
  ostream& Write_routes(){
    for(int i=0;i<routes_.size();i++){
      Route route=routes_[i];
      std::cout<<route.get_bus().first<<" "<<route.get_bus().second<<" "<<route.get_route_number_()<<" "<<route.get_driver_name()<<"\n";
    }
    cout<<"\n";
    return cout;
  }

  map<string,Route> collection_by_driver_name() {
    map<string,Route> collection;
    for (int i = 0; i < routes_.size(); i++){
      collection.insert(make_pair(routes_[i].get_driver_name(),routes_[i]));
    }
  }

  set<int> UniqueRoutes(){
    set<int> unique_routes;
    for(int i;i<routes_.size();i++){
      unique_routes.insert(routes_[i].get_route_number_());
    }
    return unique_routes;
  }

  vector<int> BusByRoute(int route){
    vector<int> bus_by_route;
    for(int i;i<routes_.size();i++){
      if(routes_[i].get_route_number_()==route){
        bus_by_route.push_back(routes_[i].get_bus().first);
      }
    }
    return bus_by_route;
  }

  vector<string> DriverByRoute(int route){
    vector<string> driver_by_route;
    for(int i;i<routes_.size();i++){
      if(routes_[i].get_route_number_()==route){
        driver_by_route.push_back(routes_[i].get_driver_name());
      }
    }
    return driver_by_route;
  }

  void DeleteByRouteNumber(int route_num){
    for(int i;i<routes_.size();i++){
      if(routes_[i].get_route_number_()==route_num){
        routes_.erase(routes_.begin()+i);
      }
    }
  }

  void ChangeDriverName(string old_name, string new_name){
    for(int i;i<routes_.size();i++){
      if(routes_[i].get_driver_name()==old_name){
        routes_[i].set_driver_name(new_name);
      }
    }
  }

  void ChangeBus(string old_model, string new_model){
    for(int i;i<routes_.size();i++){
      if(routes_[i].get_bus().second==old_model){
        routes_[i].set_model(new_model);
      }
    }
  }
};
#endif //PRACTICE10__ROUTES_COLLECTION_H_
