//
// Created by Victor on 14.01.2021.
//

#ifndef EXAM_SEM_1__AUTHOR_H_
#define EXAM_SEM_1__AUTHOR_H_
#include <iostream>
using std::string;
namespace exam{
class Author {
 private:
  string last_name_;
  string first_name_;
  string second_name_;
  short birth_year_;

 public:
  Author(string last_name, string first_name);
  Author(string last_name, string first_name, short birth_year);
  Author(string last_name, string first_name, string second_name, short birth_year);
  ~Author()=default;
  string last_name(){return last_name_;}
  string first_name(){return first_name_;}
  string second_name(){return second_name_;}
  short birth_year(){return birth_year_;}
  string full_name(){return last_name_+first_name_+second_name_;}
  bool operator==(const Author &other);
};
}
#endif //EXAM_SEM_1__AUTHOR_H_
