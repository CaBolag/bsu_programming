#include "headers.h"
int main() {
  tourAgency agency;
  std::cout<<"Enter filename for buses: ";
  std::string filename;
  std::cin>> filename;
  agency.ReadBuses(filename);
  std::cout<<"Enter filename for routes: ";
  std::string filename1;
  std::cin>> filename1;
  agency.ReadRoutes(filename1);
  bool flag= true;
  while(flag) {
    std::string route_name;
    std::cout<<"Hello, enter the name of your route: ";
    std::cin>>route_name;
    agency.AddCompletedRoute(route_name);
    std::cout<<"If want to end, enter 'end', else 'continue'";
    std::string flag_name;
    std::cin>>flag_name;
    if(flag_name=="end"){
      flag= false;
    }
  }

  agency.PrintCompletedRoutes("output.txt");
  agency.SearchByRoute("Minsk-Moscow");
  return 0;
}
