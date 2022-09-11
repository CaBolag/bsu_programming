#include "Country.h"


std::string Country::ToString(){
    std::string str=this->country_name+"("+this->country_code+"): ";
    for(int i= 1960;i<=1960+this->year_population.size()-1;i++) {
        std::map<int,long long>::iterator it=this->year_population.find(i);
        str+=std::to_string(it->second) + "[" + std::to_string(it->first)+"], ";
    }
    if(*(str.end()-2)==','){
        str.erase(str.length()-2,2);
    }
    return str;
}

std::string Country::ToString(Country country) {
    std::string str=country.country_name+"("+country.country_code+"): ";
    for(int i= 1960;i<=1960+country.year_population.size()-1;i++) {
        std::map<int,long long>::iterator it=country.year_population.find(i);
        str+=std::to_string(it->second) + "[" + std::to_string(it->first)+"], ";
    }
    if(*(str.end()-2)==','){
        str.erase(str.length()-2,2);
    }
    return str;
}
