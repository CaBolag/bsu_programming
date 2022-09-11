#include "headers.h"
int main() {
  CityService service;
  service.ReadARS("ars.txt");
  service.PrintARS("output.txt");
  service.AddCompletedWork("work1.txt");
  service.SearchByLicencePlate("1234AB");
  service.Change("1234AB");
  //service.PrintWorks("output.txt");
  service.DeleteCarByLicencePlate("1234AB");
  service.PrintWorks("output.txt");
  service.PrintCars("output.txt");
  return 0;
}
