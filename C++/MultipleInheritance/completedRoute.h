
#ifndef MULTIPLE_INHERITANCE__COMPLETEDROUTE_H_
#define MULTIPLE_INHERITANCE__COMPLETEDROUTE_H_
#include "headers.h"
class completedRoute:private Bus,private Route{
 private:
  std::string start_data;
  std::string finish_data;
  size_t passengers_amount;
 public:
  completedRoute()=default;
  ~completedRoute()=default;
  using Bus::getNumber;
  using Bus::getMaxPasangers;
  using Bus::setNumber;
  using Route::getName;
  using Route::getCost;
  using Route::setName;
  using Route::setCost;

  std::string getStartData() const {return start_data;}
  void setStartData(std::string data_){start_data=data_;}
  std::string getFinishData()const {return finish_data;}
  void setFinishData(std::string data_){finish_data=data_;}

  size_t getAmountPas() const {return passengers_amount;}
  void setAmountPas(size_t amount){passengers_amount=amount;}

  friend std::ostream& operator<<(std::ostream& out, const completedRoute&);
};

std::ostream& operator<<(std::ostream& out, const completedRoute& route){
  out<<"Name: "<<route.getName()<<"\n";
  out<<"Bus number: "<<route.getNumber()<<"\n";
  out<<"Passengers amount: "<<route.passengers_amount<<"\n";
  out<<"Start data: "<<route.getStartData()<<"\n";
  out<<"Finish data: "<<route.getFinishData()<<"\n";
  out<<"Cost: "<<route.getCost()<<"\n";
  return out;
}
#endif //MULTIPLE_INHERITANCE__COMPLETEDROUTE_H_
