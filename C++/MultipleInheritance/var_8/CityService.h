//
// Created by Victor on 15.02.2021.
//

#ifndef VAR_8__CITYSERVICE_H_
#define VAR_8__CITYSERVICE_H_
#include "headers.h"
class CityService{
 private:
  std::vector<AutoRepairShops> ars_;
  std::vector<CompletedWork> works_;
  std::vector<RepairedAuto> cars_;
 public:
  void ReadARS(std::string filename);
  void PrintARS(std::string filename);
  void PrintWorks(std::string filename);
  void PrintCars(std::string filename);
  void AddCompletedWork(std::string filename);
  void SearchByLicencePlate(std::string licence_plate);
  void DeleteCarByLicencePlate(std::string licence_plate);
  void Change(std::string licence_plate);
};

void CityService::ReadARS(std::string filename) {
  std::ifstream in (filename);
  if(!in.is_open()){
    std::cout<<"Error!";
    return;
  }
  while(!in.eof()){
    std::string str;
    std::getline(in,str);
    std::stringstream string_stream(str);
    AutoRepairShops ars;
    string_stream>>ars;
    ars_.push_back(ars);
  }
}

void CityService::PrintARS(std::string filename) {
  std::ofstream out (filename);
  out<<"AutoRepairShops:\n";
  std::copy(ars_.begin(),ars_.end(),std::ostream_iterator<AutoRepairShops>(out,"\n"));
}


void CityService::PrintWorks(std::string filename) {
  std::ofstream out (filename,std::ios::app);
  out<<"Completed works:\n";
  std::copy(works_.begin(),works_.end(),std::ostream_iterator<CompletedWork>(out,"\n"));
}

void CityService::PrintCars(std::string filename) {
  std::ofstream out (filename,std::ios::app);
  out<<"Repaired cars:\n";
  std::copy(cars_.begin(),cars_.end(),std::ostream_iterator<RepairedAuto>(out,"\n"));
}
 void CityService::AddCompletedWork(std::string filename) {
  std::ifstream in (filename);
  if(!in.is_open()){
    std::cout<<"Error!";
    return;
  }
  RepairedAuto car;
  in>>car;
  std::string brand=car.GetBrand();
  auto iterator=std::find_if(ars_.begin(),ars_.end(),
                             [brand](const AutoRepairShops& ars){
                               std::vector<std::string> brands=ars.GetBrands();
    for(int i=0;i<brands.size();i++){
      if(brands[i]==brand){
        return true;
      }
    }
    return false;
  });
  if(iterator==ars_.end()){
    std::cout<<"We can't repair your brand";
    return;
  }
  std::vector<AutoRepairShops> temp;
  while(iterator!=ars_.end()){
    temp.push_back(*iterator);
    iterator=std::find_if(iterator+1,ars_.end(),[brand](const AutoRepairShops& ars){
                            std::vector<std::string> brands=ars.GetBrands();
                            for(int i=0;i<brands.size();i++){
                              if(brands[i]==brand){
                                return true;
                              }
                            }

                            return false;
                          });
  }

  std::copy(temp.begin(),temp.end(),std::ostream_iterator<AutoRepairShops>(std::cout,"\n"));
  std::cout<<"Enter the number of ars: ";
  int ars_number;
  std::cin>>ars_number;

  CompletedWork work;
  work.SetNumber(ars_number);
  std::string start_data;
  std::cout<<"Enter start data of the repair: ";
  std::cin>>start_data;
  std::string finish_data;
  std::cout<<"Enter finish data of the repair: ";
  std::cin>>finish_data;

  work.SetStart(start_data);
  work.SetFinish(finish_data);

  std::string repair_type;
  std::cout<<"Enter the type of the repair: ";
  std::cin>>repair_type;
  work.SetRepairType(repair_type);

  int coast;
  std::cout<<"Enter the coast of the repair: ";
  std::cin>>coast;
  work.SetCoast(coast);

  auto iterator1=std::find_if(ars_.begin(),ars_.end(),[ars_number](const AutoRepairShops& ars){return ars_number==ars.GetNumber();});
  std::vector<Master> temp1=iterator1->GetMasters();
  std::copy(temp1.begin(),temp1.end(),std::ostream_iterator<Master>(std::cout,"\n"));
  std::cout<<"Enter the surname of master: ";
  std::string surname;
  std::cin>>surname;
  auto iterator2=std::find_if(temp1.begin(),temp1.end(),[surname](const Master& master){return surname==master.GetSurname();});
  work.SetMaster(*iterator2);

  work.SetLicencePlate(car.GetLicencePlate());
  cars_.push_back(car);
  works_.push_back(work);
 }

 void CityService::SearchByLicencePlate(std::string licence_plate) {
   std::vector<CompletedWork> search_by_lp;
   auto iterator=std::find_if(cars_.begin(),cars_.end(),[licence_plate](const RepairedAuto& car){return licence_plate==car.GetLicencePlate();});
   std::cout<<"Information about auto:\n"<<*iterator;
   std::copy_if(works_.begin(),works_.end(),std::back_inserter(search_by_lp),[licence_plate](const CompletedWork& work){return licence_plate==work.GetLicencePlate();});
   std::cout<<"Completed works with this car:"<<"\n";
   std::copy(search_by_lp.begin(),search_by_lp.end(),std::ostream_iterator<CompletedWork>(std::cout,"\n"));
 }

 void CityService::DeleteCarByLicencePlate(std::string licence_plate) {
   auto iterator=std::find_if(cars_.begin(),cars_.end(),[licence_plate](const RepairedAuto& car){return licence_plate==car.GetLicencePlate();});
   iterator->SetBrand("");
   iterator->SetRegistrationNumber(0);
   iterator->SetOwnerSurname("");
   iterator->SetOwnerAddress("");
   iterator->SetYear(0);
 }
 void CityService::Change(std::string licence_plate) {
   std::vector<CompletedWork> search_by_lp;
   std::copy_if(works_.begin(),works_.end(),std::back_inserter(search_by_lp),[licence_plate](const CompletedWork& work){return licence_plate==work.GetLicencePlate();});
   std::cout<<"Completed works with this car:"<<"\n";
   std::copy(search_by_lp.begin(),search_by_lp.end(),std::ostream_iterator<CompletedWork>(std::cout,"\n"));
   int choice;
   enum task {
     finish_data = 1, coast
   };
   std::cout<<"Enter the number of work: ";
   int number;
   std::cin>>number;
   std::cout<<"Enter, what do you want to do:\n1-finish_data\n2-coast\n";
   std::cin>>choice;
   switch (choice) {
     case finish_data:{
       std::string data;
       std::cout<<"Enter new data: ";
       std::cin>>data;
       works_[number-1].SetFinish(data);
       break;
     }
     case coast:{
       int coast;
       std::cout<<"Enter new coast: ";
       std::cin>>coast;
       works_[number-1].SetCoast(coast);
       break;
     }
   }
 }

#endif //VAR_8__CITYSERVICE_H_
