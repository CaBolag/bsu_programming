//
// Created by Victor on 15.02.2021.
//

#ifndef VAR_8__MASTER_H_
#define VAR_8__MASTER_H_
#include "headers.h"
class Master{
 private:
  std::string  surname_;
  int ars_number_;
  std::string address_;
  int salary_;
 public:
  Master()=default;
  ~Master()=default;
  std::string GetSurname() const {return surname_;}
  std::string GetAddress() const {return address_;}
  int GetSalary() const {return salary_;}
  friend std::istream& operator>>(std::istream& in, Master& master);

};
std::ostream& operator<<(std::ostream& out, const Master& master){
  out<<"Surname: "<<master.GetSurname() <<"\n";
  out<<"Address:: "<<master.GetAddress() <<"\n";
  out<<"Salary: "<<master.GetSalary() <<"\n";
}

std::istream& operator>>(std::istream& in, Master& master){
  in>>master.surname_>>master.address_>>master.ars_number_>>master.salary_;
  return in;
}
#endif //VAR_8__MASTER_H_
