#include <iostream>
#include <fstream>
#include "Base_car.h"
#include "Mercedes.h"
#include "Audi.h"
#include "Bmw.h"
#include "Program.h"
//8. Таксопарк. Определить иерархию легковых автомобилей. Создать таксопарк.
// Подсчитать стоимость автопарка. Провести сортировку автомобилей парка по расходу
//топлива. Найти автомобиль в компании, соответствующий заданному диапазону параметров скорости.


Base_car* get_ptr(char marker)
{
  if (marker == 'M')
    return new Mercedes;
  else if (marker == 'A')
    return new Audi;
  else if (marker == 'B')
    return new Bmw;
}


int main() {

  std::vector<Base_car*> cars;
  std::ifstream file("input.txt");
  if (!file.is_open()){
    throw std::exception();
  }
  while (true)
  {
    char marker;
    file >> marker;
    if (file.eof())
      break;
    cars.push_back(get_ptr(marker));
    string str;
    getline(file, str);
    std::istringstream stream(str);
    cars.back()->read(stream);
  }
  Program program(cars);
  program.print_cars();
  std::vector<Base_car*> cars_speed=program.find_speed(240,260);
  std::cout<<"\n\n";
  std::cout<<program.price_park()<<std::endl;
  std::ostream_iterator<Base_car*&> out_cars(cout);
  copy(cars_speed.begin(),cars_speed.end(),out_cars);
  std::cout<<"\n\n";
  program.sort_consumption();
  program.print_cars();
  for_each(cars.begin(), cars.end(),
           [](Base_car* & elem)
           {delete elem; });
  return 0;


}
