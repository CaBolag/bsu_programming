//
// Created by Victor on 15.11.2020.
//

#include "Program.h"
#include "WorldRegionPopulation!.h"

void Program::ReadCountryPopulationFromFile(std::string file_name1="C:\\Clion projects\\practice\\practice_6\\countries.csv",
                                            std::string file_name2="C:\\Clion projects\\practice\\practice_6\\world_population_1960-2018.csv";){
    //Чтение из первого файла вектора <CountryFeature>
    CountryFeature country_feature;
    country_feature.ReadCountryFeatureFromFile(file_name1);
    std::vector<CountryFeature> CountriesFeatures=country_feature.get_counties_feature();

    //Чтение из второго файла данных вектора <Country> (для получение country_name, year_population)
    WorldPopulation world_population;
    world_population.ReadCountryPopulationFromFile(file_name2);

    //Создание нового вектора на основе двух предыдущих
    for(int i=0;i<world_population.countries.size();i++){
        WorldCountry worldCountry(world_population.countries[i].country_name,CountriesFeatures[i],world_population.countries[i].year_population);
        countries_data.push_back(worldCountry);
    }
}

std::vector<WorldCountry> Program::ChooseByIncomeGroup (std::string income_group){
    std::vector<WorldCountry> countriesByIncomeGroup;
    for(const WorldCountry& worldCountry:countries_data){
        if(worldCountry.get_feature().get_group()==income_group){
            countriesByIncomeGroup.push_back(worldCountry);
        }
    }
    return countriesByIncomeGroup;
}

std::vector<WorldCountry> Program::ChooseByRegion (std::string region){
    std::vector<WorldCountry> countriesByRegion;
    for(const WorldCountry& worldCountry:countries_data){
        if(worldCountry.get_feature().get_region()==region){
            countriesByRegion.push_back(worldCountry);
        }
    }
    return countriesByRegion;
}

void Program::WriteWorldRegionPopulationToFile(std::string file_name="C:\\Clion projects\\practice\\practice_6\\output_7.csv"){
    std::ofstream fout(file_name);
    fout<<"Region;";
    for(int i=1960;i<=2018;i++){
        fout<<i<<";";
    }
    fout<<"\n";
    CountryFeature country_feature;
    Program program;
    WorldRegionPopulation region_population;
    std::set<std::string> regions= country_feature.GetUniqueRegions();
    for(std::string region_name:regions){
        fout<<region_name<<";";
        region_population.set_region(region_name);
            for(int i=1960;i<=2018;i++){
                region_population.set_year_population(std::pair<int,long long>(i,0));
            }
            region_population.CalcWorldRegionPopulation();
        for(int i=1960;i<=2018;i++) {
            fout << region_population.get_year_population()[i]<<";";
        }
        fout<<std::endl;
    }
}









