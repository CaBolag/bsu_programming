#include "headers.h"

int main() {
  GreenHouse green_house;
  vector<FlowerBed> data;
  //1
  data=green_house.ReadData("input.txt");
  //2
  green_house.SortByShape(data);
  string filename="output.txt";
  green_house.PrintData(data,filename);
  //3
  multimap<Shape,FlowerBed> data_map=green_house.MoveToContainer(data);
  //4.2
  green_house.PrintFlowersByNumber(data,filename,2);
  //4.3
  green_house.PrintVarietyOfFlowers(data,filename);
  //5.1
  vector<FlowerBed> max_flowers=green_house.FbedWithMaxFlowers(data);
  green_house.PrintData(max_flowers,filename);
  //5.3
  vector<FlowerBed> the_same_flowers=green_house.TheSameFlowers(data);
  green_house.PrintData(the_same_flowers,filename);
  //6.1
  int flowers_in_circle_fbed=green_house.FlowersInCircleFbed(data_map);
  ofstream out (filename,ios::app);
  out<<"\nAmount of flowers in circle flower bed: "<<flowers_in_circle_fbed<<"\n";
  //6.3
  vector<FlowerBed> fbeds_with_amount=green_house.FbedsWithAmountOfFlowers(data,2);
  out<<"\nFlower beds with 2 flowers:"<< "\n";
  green_house.PrintData(fbeds_with_amount,filename);
  out<<"\n";
  //6.4
  vector<FlowerBed> by_shape=green_house.SearchByShape(data,CIRCLE);
  out<<"Flower beds with circle shape:\n";
  green_house.PrintData(by_shape,filename);
  return 0;
}
