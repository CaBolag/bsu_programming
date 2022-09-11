
#ifndef MULTIPLE_INHERITANCE__ROUTE_H_
#define MULTIPLE_INHERITANCE__ROUTE_H_
#include "headers.h"
class Route
{
 private:
  std::string name;
  std::string start;
  std::string finish;
  double km;
  double cost;
 public:
  Route() = default;
  ~Route() = default;
  std::string getName() const { return name; }
  std::string getStart() const { return start; }
  std::string getFinish() const { return finish; }
  double getKm() const { return km; }
  double getCost() const { return cost; }
  void setName(std::string _name) { name = _name; }
  void setCost(double _cost) { cost = _cost; }
  friend std::istream& operator>>(std::istream&, Route&);
  friend std::ostream& operator<<(std::ostream&, const Route&);
};

std::ostream& operator<<(std::ostream& out, const Route& route)
{
  out <<"Route name: " << route.name
      << "Rout start: " << route.start
      <<"Rout finish: " << route.finish
      << "Route km: " << route.km
      << "Rout cost: " << route.cost;
  return out;
}

std::istream& operator>>(std::istream& in, Route &route)
{
  in >> route.name >> route.start >> route.finish >> route.km >> route.cost;
  return in;
}
#endif //MULTIPLE_INHERITANCE__ROUTE_H_
