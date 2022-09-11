//
// Created by Victor on 08.02.2021.
//

#ifndef INC_08_02__FLOWERBED_H_
#define INC_08_02__FLOWERBED_H_
#include "headers.h"
using namespace std;
enum Shape
{
  CIRCLE,
  SQUARE,
  RHOMBUS
};
class FlowerBed{
 private:
  int bed_number_;
  Shape shape_;
  vector<string> flowers_;
 public:
  FlowerBed()=default;
  ~FlowerBed()=default;
  void SetNumber(int number){bed_number_=number;};
  void SetShape(Shape shape){shape_=shape;};
  void SetFlowers(const std::vector<std::string>& flowers){flowers_=flowers;};
  int GetNumber() const {return bed_number_;}
  Shape GetShape() const {return shape_;}
  vector<string> GetFlowers() const {return flowers_;}
  static Shape GetShapeByString(const std::string& shapeString);

};
std::istream& operator>>(istream& in, FlowerBed&);
std::ostream& operator<<(std::ostream&, const FlowerBed&);

#endif //INC_08_02__FLOWERBED_H_
