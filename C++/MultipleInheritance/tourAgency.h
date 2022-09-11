

#ifndef MULTIPLE_INHERITANCE__TOURAGENCY_H_
#define MULTIPLE_INHERITANCE__TOURAGENCY_H_
#include "headers.h"
class tourAgency{
 private:
  std::vector<Bus> buses;
  std::vector<Route> routes;
  std::vector<completedRoute> completed_routes;
 public:
  tourAgency()=default;
  ~tourAgency()=default;
  void ReadBuses(std::string filename);
  void PrintBuses(std::string filename);
  void ReadRoutes(std::string filename);
  void PrintRoutes(std::string filename);
  void PrintCompletedRoutes(std::string filename);
  void AddCompletedRoute(std::string route_name);
  void SearchByRoute(std::string route);
};
void tourAgency::ReadBuses(std::string filename) {
  std::ifstream in (filename);
  if(!in.is_open()){
    std::cout<<"Error!";
    return;
  }
  while(!in.eof()){
    Bus bus_;
    in>>bus_;
    buses.push_back(bus_);
  }
}

void tourAgency::ReadRoutes(std::string filename) {
  std::ifstream in (filename);
  if(!in.is_open()){
    std::cout<<"Error!";
    return;
  }
  while(!in.eof()){
    Route route_;
    in>>route_;
    routes.push_back(route_);
  }
}

void tourAgency::PrintBuses(std::string filename) {
  std::ofstream out (filename);
  std::copy(buses.begin(),buses.end(),std::ostream_iterator<Bus>(out,"\n"));
}

void tourAgency::PrintRoutes(std::string filename) {
  std::ofstream out (filename);
  std::copy(routes.begin(),routes.end(),std::ostream_iterator<Route>(out,"\n"));
}

void tourAgency::PrintCompletedRoutes(std::string filename) {
  std::ofstream out (filename);
  std::copy(completed_routes.begin(),completed_routes.end(),std::ostream_iterator<completedRoute>(out,"\n"));
}

void tourAgency::AddCompletedRoute(std::string route_name) {
  auto iterator=std::find_if(routes.begin(),routes.end(),
                             [route_name](const Route& route){return route.getName()==route_name;});
  if(iterator==routes.end()){
    std::cout<<"Route is not found";
    return;
  }

  completedRoute completed_route;
  completed_route.setName(iterator->getName());
  completed_route.setCost(iterator->getCost());
  size_t amount;
  std::cout<<"Enter the number of passengers: ";
  std::cin>>amount;
  std::vector<Bus> temp;
  auto iterator1=std::find_if(buses.begin(),buses.end(),
                              [amount](const Bus& bus){return amount<=bus.getMaxPasangers();});
  if(iterator1==buses.end()){
    std::cout<<"Bus is not found";
    return;
  }

  while(iterator1!=buses.end()){
    temp.push_back(*iterator1);
    iterator1=std::find_if(iterator1+1,buses.end(),
                           [amount](const Bus& bus){return amount<=bus.getMaxPasangers();});
  }

  std::copy(temp.begin(),temp.end(),std::ostream_iterator<Bus>(std::cout,"\n"));
  std::cout<<"Enter the number of bus from the list above: ";
  std::string bus_number;
  std::cin>>bus_number;
  completed_route.setNumber(bus_number);

  std::string start_data;
  std::cout<<"Enter start data of your route: ";
  std::cin>>start_data;
  std::string finish_data;
  std::cout<<"Enter finish data of your route: ";
  std::cin>>finish_data;

  completed_route.setStartData(start_data);
  completed_route.setFinishData(finish_data);
  completed_routes.push_back(completed_route);
}

void tourAgency::SearchByRoute(std::string route) {
  std::vector<completedRoute> search_by_route;
  std::copy_if(completed_routes.begin(),completed_routes.end(),std::back_inserter(search_by_route),
               [route](completedRoute completed_route){return completed_route.getName()==route;});
  std::copy(search_by_route.begin(),search_by_route.end(),std::ostream_iterator<completedRoute>(std::cout,"\n"));
  std::set<Bus> buses_by_route;
  for(size_t i=0;i<search_by_route.size();i++){
    completedRoute element=search_by_route[i];
    std::copy_if(buses.begin(),buses.end(),std::inserter(buses_by_route,buses_by_route.begin()),
                 [element](const Bus& bus){return bus.getNumber()==element.getNumber();});
  }
  std::cout<<"Buses for this route:"<<"\n";
  std::copy(buses_by_route.begin(),buses_by_route.end(),std::ostream_iterator<Bus>(std::cout,"\n"));
}
#endif //MULTIPLE_INHERITANCE__TOURAGENCY_H_
