#ifndef WEEK_8_GOOGLE_TESTS_TESTING_H
#define WEEK_8_GOOGLE_TESTS_TESTING_H

#include<string>
#include <vector>
#include<fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
std::vector<std::string> File_reader(std::string file_name);
std::vector<std::string> DeleteElements(std::ifstream &in, std::string delete_word);
std::vector<std::string> Sort_strings(std::string file_name);
void File_output(std::vector<std::string>,std::string file_name);
#endif //WEEK_8_GOOGLE_TESTS_TESTING_H
