#include <iostream>
#include "Country.h"
#include "WorldPopulation.h"
#include "CountryFeature.h"
#include "Program.h"
#include <string>
std::ifstream& operator >>(std::ifstream& in,CountryFeature &country_feature);
std::ostream& operator <<(std::ostream & out,const CountryFeature &country);
int main() {
    //Проверка работы метода ToString
    std::map <int,long long int> country1;
    country1.emplace(1960,9000000);
    country1.emplace(1961,10000000);
    Country country{"Belarus","Bel",country1};
    std::string str_out=country.ToString();
    std::cout<<str_out<<std::endl;
    std::string new_str=Country::ToString(country);
    std::cout<<new_str;

    WorldPopulation countries_data;
    countries_data.ReadCountryPopulationFromFile("C:\\Clion projects\\practice\\practice_6\\world_population_1960-2018.csv");
    countries_data.CalcWorldPopulation();
    countries_data.WriteWorldPopulationToFile("C:\\Clion projects\\practice\\practice_6\\output.csv");

    //2. Создайте коллекцию стран, прочитав данные их исходного файла
    std::vector<CountryFeature> CountriesFeatures;
    CountryFeature country_feature;
    std::ifstream fin("C:\\Clion projects\\practice\\practice_6\\countries.csv");
    std::string header_string;
    getline(fin,header_string);
    if (!fin.is_open()){
        std::cout<<"Error";
        return 0;
    }
    while(!fin.eof()){
        fin >> country_feature;
        CountriesFeatures.push_back(country_feature);
    }

    return Program::Main();
}
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
//3.Реализуйте перегрузку operator<< для классов CountryFeature
std::ostream& operator <<(std::ostream& out,const CountryFeature& country){

    out<<country.get_code()<<";";
    out<<country.get_region()<<";";
    out<<country.get_group()<<";";
    return out;
}
