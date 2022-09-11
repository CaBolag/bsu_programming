
#ifndef KR_2_2020__FILEREADER_H_
#define KR_2_2020__FILEREADER_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::string;
using std::vector;

class FileReader {
 public:
  vector<string> ReadLines(const string &file_path); // чтение строк из файла
  vector<string> ReadWords(const string &file_path); // вызов функции чтения строк из файла, и парсинг строк на слова
};

vector<string> FileReader::ReadLines(const string &file_path) {
  std::ifstream fin(file_path);
  std::string line;
  std::vector<string> lines;
  if(!fin.is_open()){
    throw std::exception();
  }
  while(!fin.eof()){
    std::getline(fin,line);
    lines.push_back(line);
  }
  return lines;
}

vector<string> FileReader::ReadWords(const string &file_path) {
  std::vector<string> lines=ReadLines(file_path);
  string word;
  std::vector<string> words;
  for(int i=0;i<lines.size();i++){
    std::string line=lines[i];
    std::stringstream str(line);
    while(!str.eof()){
      std::getline(str,word,' ');
      words.push_back(word);
    }
  }
  return words;
}
#endif //KR_2_2020__FILEREADER_H_
