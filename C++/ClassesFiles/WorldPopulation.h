#ifndef PRACTICE_6_WORLDPOPULATION_H
#define PRACTICE_6_WORLDPOPULATION_H
#include <iostream>
#include <vector>
#include <map>
#include "Country.h"
#include <fstream>
#include <sstream>
struct WorldPopulation{
    std::vector<Country> countries;
    std::map<int,long long int> year_population;
    void ReadCountryPopulationFromFile(std::string file_name);
    void CalcWorldPopulation();
    void WriteWorldPopulationToFile(std::string file_name);
};
#endif //PRACTICE_6_WORLDPOPULATION_H
