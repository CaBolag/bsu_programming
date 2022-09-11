#ifndef PRACTICE_6_COUNTRY_H
#define PRACTICE_6_COUNTRY_H
#include <map>
#include <iostream>
#include <iterator>

struct Country{
    std::string country_name;
    std::string country_code;
    std::map<int,long long int> year_population;
    std::string ToString();
    static std::string ToString(Country country);

};
std::ostream & operator <<(std::ostream & out,const Country &country){
    std::string str=country.ToString();
    out<<str;
    return out;
}
#endif //PRACTICE_6_COUNTRY_H
