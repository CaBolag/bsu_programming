//
// Created by Victor on 15.11.2020.
//

#ifndef PRACTICE_6_WORLDCOUNTRY_H
#define PRACTICE_6_WORLDCOUNTRY_H
#include "CountryFeature.h"
#include <iostream>
#include <map>
//4. По аналогии со структурой Country создайте класс WorldCountry c полями:
// string сountry_name, CountryFeature country_feature, map<int, long long int> year_population.
class WorldCountry{
private:
    std::string country_name;
    CountryFeature country_feature;
    std::map<int, long long int> year_population;
public:
    WorldCountry(const std::string& _country_name, const CountryFeature& _country_feature,const std::map<int, long long int>& _year_population):
    country_name(_country_name),country_feature(_country_feature),year_population(_year_population){}
    std::string get_name() const {return this->country_name;};
    CountryFeature get_feature() const {return this->country_feature;};
    std::map<int, long long int> get_year_population() const {return this->year_population;};
};

#endif //PRACTICE_6_WORLDCOUNTRY_H
