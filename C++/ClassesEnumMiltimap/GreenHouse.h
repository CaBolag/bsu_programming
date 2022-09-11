
#ifndef INC_08_02__GREENHOUSE_H_
#define INC_08_02__GREENHOUSE_H_
#include "headers.h"

class GreenHouse{
 public:
  static vector<FlowerBed> ReadData(string filename);//Разместить данные в последовательном контейнере (1).
  static void PrintData(vector<FlowerBed>,string filename);

  static void SortByShape(vector<FlowerBed>); //Выполнить сортировку по геометрической форме клумбы (2).
  static multimap<Shape,FlowerBed> MoveToContainer(vector<FlowerBed>); //Далее данные из (1) размещаются в ассоциативный контейнер. Использовать как ключ (3)(MULTIMAP).
  static void PrintFlowersByNumber(vector<FlowerBed>,string filename,int bed_number);//4.2) вывести список всех цветов указанной клумбы
  static void PrintVarietyOfFlowers(vector<FlowerBed>,string filename); //4.3) вывести список всех видов цветов;
  static vector<FlowerBed> FbedWithMaxFlowers(vector<FlowerBed>);  //5.1) найти клумбу с наибольшим количеством цветов; (я вывожу КЛУМБЫ (а не клумбу), если несколько клумб имеют одинаковое(макс) кол-во цветов));
  static vector<FlowerBed> TheSameFlowers(vector<FlowerBed>);  //5.3) найти клумбу с только одним видом цветов; (как и в 5.1 вывожу КЛУМБЫ)

  static int FlowersInCircleFbed(const multimap<Shape,FlowerBed>&);  //6.1) подсчет числа цветков на всех круглых клумбах (с функцией);
  static vector<FlowerBed> FbedsWithAmountOfFlowers(vector<FlowerBed>,int amount);  //6.3) поиск клумб с заданным числом цветов (функц объект);

  static vector<FlowerBed> SearchByShape(vector<FlowerBed>,Shape shape); //6.4) поиск всех клумб указанной формы
 private:
  class CompareWithAmount{
   private:
    int amount_;
   public:
    CompareWithAmount(int amount):amount_(amount){};
    bool operator() (const FlowerBed& element){
      return(element.GetFlowers().size()==amount_);
    }
  };

  struct CompareByShape {
    bool operator()(const FlowerBed& a, const FlowerBed& b) {
      return a.GetShape() < b.GetShape();
    }
  };

};

#endif //INC_08_02__GREENHOUSE_H_
