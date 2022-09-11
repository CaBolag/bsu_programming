//
// Created by Victor on 15.11.2020.
//

#ifndef PRACTICE_6_PROGRAM_H
#define PRACTICE_6_PROGRAM_H
#include <string>
#include "WorldCountry.h"
#include "WorldPopulation.h"
#include "CountryFeature.h"
#include "WorldRegionPopulation!.h"
#include <vector>
class Program{

public:
    static int Main();

    std::vector<WorldCountry> countries_data;
    // 5,12 Создайте функцию (ReadCountryPopulationFromFile(string file) – чтение из файла в vector<WorldCountry>) –
    // функцию-член класса Program, в которой на основе коллекций, содержащих объекты классов Country, CountryFeature
    // создать коллекцию объектов класса WorldCountry.
    void ReadCountryPopulationFromFile(std::string, std::string);
    //6. Разработайте метод выбора стран из коллекции (аргументом будет уровень дохода страны),
    //содержащей объекты класса WorldCountry, удовлетворяющих условиям:
    //доход страны = High income (или = Low income, или = Lower middle income, или = Upper middle income).
    std::vector<WorldCountry> ChooseByIncomeGroup (std::string income_group);
    //8. Разработайте метод формирование коллекции стран, принадлежащих какому-то региону (аргументом будет регион).
    std::vector<WorldCountry> ChooseByRegion (std::string region);
    //11,12 Для класса Program создайте метод void WriteWorldRegionPopulationToFile(string file) –
    // запись в файл статистики мироворого населения по годам для каждого региона, в формате:
    void WriteWorldRegionPopulationToFile(std::string file_name);
private:
    WorldPopulation world_population;

};
#endif //PRACTICE_6_PROGRAM_H
