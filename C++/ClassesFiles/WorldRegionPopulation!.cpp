//
// Created by Victor on 24.11.2020.
//

#include "WorldRegionPopulation!.h"


void WorldRegionPopulation::CalcWorldRegionPopulation() {
    Program program;
    std::vector<WorldCountry> countries_by_region = program.ChooseByRegion(region);
    for (const WorldCountry &country:countries_by_region) {
        for (auto year_population_pair:country.get_year_population()) {
            year_population[year_population_pair.first] += year_population_pair.second;
        }
    }
}


