
#include "headers.h"
std::istream& operator>>(istream& in, FlowerBed& flower_bed)
{
  int number;
  in >> number;
  flower_bed.SetNumber(number);
  std::string shapeString;
  in >> shapeString;
  flower_bed.SetShape(FlowerBed::GetShapeByString(shapeString));
  std::string flower;
  std::vector<std::string> flowers;
  while (in >> flower)
  {
    flowers.push_back(flower);
  }
  flower_bed.SetFlowers(flowers);
  return in;
}

std::ostream& operator<<(std::ostream& out, const FlowerBed& flower_bed)
{
  out << "Flower bed number: "<< flower_bed.GetNumber()
      << " Shape: " << flower_bed.GetShape()
      << " Flowers:";
  vector<string> flowers=flower_bed.GetFlowers();
  for(const string &flower : flowers){
    out<<" "<<flower;
  }
  return out;
}

Shape FlowerBed::GetShapeByString(const std::string &shapeString)
{
  if (shapeString == "круг")
  {
    return CIRCLE;
  }
  else if (shapeString == "квадрат")
  {
    return SQUARE;
  }
  else if (shapeString == "ромб")
  {
    return RHOMBUS;
  }
  return CIRCLE;
}
