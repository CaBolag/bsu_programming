//
// Created by Victor on 15.02.2021.
//

#ifndef VAR_8__COMPLETEDWORK_H_
#define VAR_8__COMPLETEDWORK_H_
#include "headers.h"
class CompletedWork:private AutoRepairShops, private RepairedAuto{
 private:
  std::string start_repair_;
  std::string finish_repair_;
  std::string repair_type_;
  int coast_;
  Master master_;
 public:
  CompletedWork()=default;
  ~CompletedWork()=default;
  using AutoRepairShops::GetNumber;
  using RepairedAuto::GetLicencePlate;
  using AutoRepairShops::SetNumber;
  using RepairedAuto::SetLicencePlate;
  std::string GetStart() const {return start_repair_;}
  std::string GetFinish() const {return finish_repair_;}
  std::string GetType() const {return repair_type_;}
  int GetCoast() const {return coast_;}
  Master GetMaster() const{return master_;}
  void SetStart(std::string start_repair){start_repair_=start_repair;}
  void SetFinish(std::string finish_repair){finish_repair_=finish_repair;}
  void SetRepairType( std::string repair_type){repair_type_=repair_type;}
  void SetCoast(int coast){coast_=coast;}
  void SetMaster(Master master){master_=master;}

};
std::ostream& operator<<(std::ostream& out, const CompletedWork& work){
  out<<"Ars number: "<<work.GetNumber()<<"\n"
     <<"Car Licence Plate: "<<work.GetLicencePlate()<<"\n"
     <<"Start repair: "<<work.GetStart()<<"\n"
     <<"Finish repair: "<<work.GetFinish()<<"\n"
     <<"Coast: "<<work.GetCoast()<<"\n"
     <<"Master: "<<work.GetMaster()<<"\n";
}

#endif //VAR_8__COMPLETEDWORK_H_
