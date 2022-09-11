#include "WorldPopulation.h"

void WorldPopulation::ReadCountryPopulationFromFile(std::string file_name) {
    std::ifstream in_file(file_name);
    if (!in_file.is_open()) {
        std::cout << "Error file open\n";
        return;
    };
    std::string header_string;
    std::getline(in_file, header_string);
    while (!in_file.eof()) {
        std::string county_str;
        std::getline(in_file, county_str);
        std::stringstream in(county_str);
        Country country_data;
        std::getline(in, country_data.country_name, ';');
        std::getline(in, country_data.country_code, ';');
        for (int i = 1960; i <= 2018; i++) {
            long long int population = 0;
            std::string population_str;
            std::getline(in, population_str, ';');
            if (population_str.length() == 0) {
                country_data.year_population[i] = population;
            } else {
                population = std::stoll(population_str);
                country_data.year_population.insert(std::make_pair(i,population));
            }
        }
        this->countries.push_back(country_data);
    }
}

void WorldPopulation::CalcWorldPopulation(){
    for(Country country:countries){
        for(int i=1960;i<=2018;i++){
            this->year_population[i]+=country.year_population[i];
        }
    }
}

void WorldPopulation::WriteWorldPopulationToFile(std::string file_name){
    std::ofstream out(file_name);
    for(int i=1960;i<=2018;i++){
        out<<i<<";";
    }
    out<<"\n";
    for(int i=1960;i<=2018;i++){
        out<<this->year_population[i]<<";";
    }
}