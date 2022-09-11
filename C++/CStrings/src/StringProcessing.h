

#ifndef INC_22_02__STRINGPROCESSING_H_
#define INC_22_02__STRINGPROCESSING_H_
#include<iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>

class StringProcessing {
 public:
  static void strchr(char* str, int ch,char* new_str);
  static void strchr(const std::string& str, int ch,std::string new_str);

  static void compact(char* str,char* new_str);
  static void compact(std::string& );

  static void deleteWord(char* str,char *word,char* new_str);
  static void deleteWord(std::string& str,const std::string& word);

  static void theLongest(char* str,char* the_longest);
  static void theLongest(const std::string& str,std::string the_longest);

  static void reverse(char *str,char* new_str);
  static void reverse(std::string str,std::string rev_str);

  static void replace(std::string& input_str, const std::string& replaced_str,const std::string& new_str);
  static void replace(char *input_str, char *replaced_str, char *rep_str,char* new_str);

  static std::ofstream writeComments(std::string infile_name, std::string outfile_name);
  static std::ofstream writeCommentsCstring(std::string in_file, std::string output_file);

};

#endif //INC_22_02__STRINGPROCESSING_H_
