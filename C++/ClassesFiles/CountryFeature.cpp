//
// Created by Victor on 15.11.2020.
//

#include "CountryFeature.h"
std::ifstream& operator >>(std::ifstream& in,CountryFeature &country_feature){
    std::string str;
    getline(in,str);
    std::stringstream string_stream(str);
    std::string code,region,group;
    getline(string_stream,code,';');
    country_feature.set_code(code);
    getline(string_stream,region,';');
    country_feature.set_region(region);
    getline(string_stream,group,';');
    country_feature.set_group(group);
    return in;
}

void CountryFeature::ReadCountryFeatureFromFile(std::string file_name){
    CountryFeature country_feature;
    std::ifstream fin(file_name);
    std::string header_string;
    getline(fin,header_string);
    if (!fin.is_open()){
        std::cout<<"Error";
    }
    while(!fin.eof()){
        fin >> country_feature;
        coutries_feature.push_back(country_feature);
    }
}

std::set<std::string> CountryFeature::GetUniqueRegions(){
    std::set<std::string> unique_regions;
    this->ReadCountryFeatureFromFile("C:\\Clion projects\\practice\\practice_6\\countries.csv");
    std::vector<CountryFeature> courtries_feature=this->get_counties_feature();
    for(const CountryFeature& countryFeature:courtries_feature){
        unique_regions.insert(countryFeature.get_region());
    }
    return unique_regions;
}
