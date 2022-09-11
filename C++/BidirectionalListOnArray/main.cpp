#include <iostream>
#include "vocabulary.h"
int main() {

  WordCard a("dsd");
  WordCard b(std::move(a));
  b.IncCounter();
  std::cout<<a.GetCounter();
  std::cout<<b.GetCounter()<<std::endl;


  FileReader file_reader;
  std::vector<std::string> words=file_reader.ReadWords("C:\\Clion projects\\Guseinova\\KR_2_2020\\input.txt");
  std::cout<<words.size();


  containers::BiDirectionalListOnArray<int> array;
  array.PushBack(5);
  array.PushFront(6);
  std::cout<<array.PopFront();

  Vocabulary vocabulary;
  vocabulary.ReadFileToCards("C:\\Clion projects\\Guseinova\\KR_2_2020\\input.txt");
  return 0;
}
