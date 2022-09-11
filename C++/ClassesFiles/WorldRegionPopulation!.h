//
// Created by Victor on 24.11.2020.
//

#ifndef PRACTICE_6_WORLDREGIONPOPULATION_H
#define PRACTICE_6_WORLDREGIONPOPULATION_H
#include <string>
#include <map>
#include <vector>
#include "Program.h"
//9. Создайте класс WorldRegionPopulation с двумя полями:
//region, map<int,long long int> year_population.
class WorldRegionPopulation {
private:
    std::string region;
    std::map<int, long long int> year_population;
public:
    void set_region(std::string _region){region=_region;};
    void set_year_population(std::pair<int,long long> pair){year_population.insert(pair);};
    //10. Для класса WorldRegionPopulation создайте метод (функцию-член) void CalcWorldRegionPopulation() –
    // вычисление населения всех регионах по годам, используйте коллекцию из п.8.
    void CalcWorldRegionPopulation();

    void WorldRegionPopulation(Program& _program, const std::string& _region):program(_program),region(_region){
        for(int i=1960;i<=2018;i++){
            year_population.insert(std::pair<int,long long>(i,0));
        }
        CalcWorldRegionPopulation();
    }

    std::map<int, long long> get_year_population() { return this->year_population;};
private:
    Program program;
};
#endif //PRACTICE_6_WORLDREGIONPOPULATION_H
