//
// Created by Victor on 15.02.2021.
//

#ifndef VAR_8__AUTOREPAIRSHOP_H_
#define VAR_8__AUTOREPAIRSHOP_H_
#include "headers.h"
class AutoRepairShops{
 private:
  int number_;
  std::string address_;
  std::vector<std::string> repaired_brands_;
  std::vector<Master> masters_;
 public:
  AutoRepairShops()=default;
  ~AutoRepairShops()=default;
  int GetNumber() const {return number_;}
  void SetNumber(int number){number_=number;}
  //std::string GetAddress () const {return address_;}
  std::vector<std::string> GetBrands() const {return repaired_brands_;}
  std::vector<Master> GetMasters()const{return masters_;}
  friend std::istream& operator>>(std::istream& in, AutoRepairShops& ars);
  friend std::ostream& operator<<(std::ostream& out, const AutoRepairShops& ars);
};


std::ostream& operator<<(std::ostream& out, const AutoRepairShops& ars){
  out<< "Number: "<<ars.number_<<"\n"
     << "Address: "<<ars.address_<<"\n"
     << "Masters:\n";
  std::copy(ars.masters_.begin(),ars.masters_.end(),std::ostream_iterator<Master>(out,"\n"));

}

std::istream& operator>>(std::istream& in, AutoRepairShops& ars){
  int masters_amount;
  in>>ars.number_>>ars.address_>>masters_amount;
  Master master;
  for(int i=0;i<masters_amount;i++){
    in>>master;
    ars.masters_.push_back(master);
  }
  std::string brand;
  while(!in.eof()){
    in>>brand;
    ars.repaired_brands_.push_back(brand);
  }
}
#endif //VAR_8__AUTOREPAIRSHOP_H_
