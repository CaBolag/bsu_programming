//
// Created by Victor on 14.01.2021.
//

#include "author.h"
namespace exam {
Author::Author(string last_name, string first_name) : last_name_(last_name), first_name_(first_name) {
  if (last_name.empty() or first_name.empty()) {
    throw std::invalid_argument("Error! Name is empty.");
  }
}
Author::Author(string last_name, string first_name, short birth_year) : Author(last_name, first_name) {
  if (birth_year <= 0) {
    throw std::invalid_argument("Error! Birth year is negative.");
  }
  birth_year_ = birth_year;
}
Author::Author(string last_name, string first_name, string second_name, short birth_year) :
Author(last_name,first_name,birth_year) {
  if (second_name.empty()) {
    throw std::invalid_argument("Error! Second name is empty.");
  }
  second_name_ = second_name;
}
bool Author::operator==(const Author &other) {
  if(last_name_==other.last_name_ && first_name_==other.first_name_ && second_name()==other.second_name_ && birth_year_==other.birth_year_){
    return true;
  }
  return false;
}
}
