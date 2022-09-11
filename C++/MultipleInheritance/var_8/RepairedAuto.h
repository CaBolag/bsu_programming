//
// Created by Victor on 15.02.2021.
//

#ifndef VAR_8__REPAIREDAUTO_H_
#define VAR_8__REPAIREDAUTO_H_
#include "headers.h"
class RepairedAuto{
 private:
  std::string licence_plate_;
  std::string brand_;
  int year_;
  std::string owner_surname_;
  int registration_number_;
  std::string owner_address_;
 public:
  RepairedAuto()=default;
  ~RepairedAuto()=default;
  std::string GetLicencePlate() const {return licence_plate_;}
  std::string GetBrand()const{return brand_;}
  void SetLicencePlate(std::string licence_plate){licence_plate_=licence_plate;}
  void SetBrand(std::string brand){brand_=brand;}
  void SetYear(int year){year_=year;}
  void SetOwnerSurname(std::string owner_surname){owner_surname_=owner_surname;}
  void SetRegistrationNumber(int registration_number){registration_number_=registration_number;}
  void SetOwnerAddress(std::string owner_address){owner_address_=owner_address;}
  friend  std::ostream& operator<<(std::ostream& out, const RepairedAuto car);
  friend  std::istream& operator>>(std::istream& in, RepairedAuto& car);


};
std::ostream& operator<<(std::ostream& out, const RepairedAuto car){
  out<<"Licence plate: "<<car.licence_plate_
     <<" Brand: "<<car.brand_
     <<" Year: "<<car.year_
     <<" Owner surname: "<<car.owner_surname_
     <<" Owner address: "<<car.owner_address_
     <<" Registration number: "<<car.registration_number_<<"\n";
}
std::istream& operator>>(std::istream& in, RepairedAuto& car){
  in>>car.licence_plate_>>car.brand_>>car.year_>>car.registration_number_>>car.owner_surname_>>car.owner_address_;
}
#endif //VAR_8__REPAIREDAUTO_H_
