#include "Base.h"
#include "Lolly_pop.h"
#include "Chocolate.h"
#include "Cookies.h"
#include <fstream>

using std::vector;

Base_sweet* get_ptr(char marker)//возвращает указатель
//на базовый класс, но в него указываем указатель
//производного класса, потому что базовый класс
//полиморфный (там где есть вертуальные методы)
//(тип сладости)
{
  if (marker == 'l')
    return new Lolly_pop;
  else if (marker == 'c')
    return new Cookies;
  else if (marker == 's')
    return new Chocolate;
}

int main()
{
  vector<Base_sweet*> sweets;//создаем динамический
  //массив указателей на базовый класс
  //(для того чтобы разместить там все виды сладости)
  std::ifstream file("Input.txt");
  if (!file.is_open())//сделать exception в экзаменационной задаче
  {
    cout << "ERROR: file is not open.\n";
    system("pause");
    exit(1);
  }
  while (true)
  {
    char marker;
    file >> marker;
    if (file.eof())
      break;
    sweets.push_back(get_ptr(marker));//добавляем в
    //конец вектора пустой правильный объект,
    //соответсвующей сладости
    string str;//str для прочтения оставшейся
    //части строки
    getline(file, str);//прочитали оставшуюся
    //часть строки
    std::istringstream stream(str);//создали
    //поток-строку
    //по прочитаной строке
    //для того чтобы вызвать метод read
    sweets.back()->read(stream);//.back - обращение к
    //последнему элементу вектора (указатель на
    //базовый класс с созданным правильным
    //объектом)
  }
  sort(sweets.begin(), sweets.end(), []
      (Base_sweet* & sweet1, Base_sweet* & sweet2)
  {return sweet1->get_weight() > sweet2->get_weight(); });
  cout << "Sorted sweets:\n";
  std::ostream_iterator<Base_sweet*&> out_sweets(cout);
  copy(sweets.begin(), sweets.end(), out_sweets);
  //наполнение подарка
  vector<Base_sweet*> present;
  int weight_prs;
  cout << "Enter weight of the present: ";
  cin >> weight_prs;
  bool flag = true;//для того чтобы не было вечного
  //цикла из-за веса (если свободного веса
  //осталось 3г, а минимальная конфета весит 5г)
  while (weight_prs > 0 && flag)
  {
    std::for_each(sweets.begin(), sweets.end(),
                  [&present, &weight_prs, &flag, sweets]
                      (Base_sweet* & nope_sweet)
                  {
                    //если вес текущей сладости меньше или равно
                    //свободному весу подарка,
                    if (nope_sweet->get_weight() <= weight_prs)
                    {
                      //то мы добавляем в подарок сладость
                      present.push_back(nope_sweet);
                      //и отнимаем у свободного весв подарка
                      //вес сладости
                      weight_prs -= nope_sweet->get_weight();
                    }
                    else if (weight_prs < sweets.back()->get_weight())
                      flag = false;
                  });
  }
  cout << "Our present:\n";
  copy(present.begin(), present.end(), out_sweets);

  //найти конфету в подарке по сахару
  double sugar_min, sugar_max;
  cout << "Enter % of sugar (min max): ";
  cin >> sugar_min >> sugar_max;
  cout << "Sweet with your sugar:\n";
  std::copy_if(present.begin(), present.end(), out_sweets,
               [sugar_min, sugar_max](Base_sweet* & nope_sugar)
               {return nope_sugar->get_sugar() <= sugar_max && nope_sugar->get_sugar() >= sugar_min; });

  //освобождение памяти
  for_each(sweets.begin(), sweets.end(),
           [](Base_sweet* & for_del)
           {delete for_del; });

  system("pause");
  return 0;
}
