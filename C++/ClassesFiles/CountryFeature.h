//
// Created by Victor on 15.11.2020.
//

#ifndef PRACTICE_6_COUNTRYFEATURE_H
#define PRACTICE_6_COUNTRYFEATURE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
//1.Создайте класс CountryFeature с тремя полями:
//string country_code, string region, string income_group
class CountryFeature {
private:
    std::string country_code;
    std::string region;
    std::string income_group;
    std::vector<CountryFeature> coutries_feature;
public:
    std::string get_code() const {return this->country_code;};
    std::string get_region() const { return this->region;};
    std::string get_group() const {return this->income_group;};
    std::vector<CountryFeature> get_counties_feature() const{return this->coutries_feature;};
    void set_code (std::string code){country_code=code;}
    void set_region (std::string str_region){region=str_region;}
    void set_group (std::string group){income_group=group;}
    void ReadCountryFeatureFromFile(std::string);
    //7. Разработайте метод формирования коллекции уникальных регионов из коллекции объектов CountryFeature.
    std::set<std::string> GetUniqueRegions();

};

std::ifstream& operator >>(std::ifstream& in,CountryFeature &country_feature);
#endif //PRACTICE_6_COUNTRYFEATURE_H
