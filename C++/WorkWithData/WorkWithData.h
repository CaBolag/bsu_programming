

#ifndef INC_15_02__WORKWITHDATA_H_
#define INC_15_02__WORKWITHDATA_H_
#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
/*class WorkWithData{
 private:
  std::list<std::string> data_;
 public:
  WorkWithData()=default;
  ~WorkWithData()=default;
  void SetData(std::list<std::string> data){data_=data;};
  void CopyData(std::vector<std::string> vector){
    std::copy(data_.begin(),data_.end(),std::back_inserter(vector));
  }
};*/

void CopyData(std::vector<std::string> vector,std::list<std::string> data_){
  std::copy(data_.begin(),data_.end(),std::back_inserter(vector));
}

std::list<std::string> FindByLetter(const char& character,std::list<std::string> data){
  std::list<std::string> elements;
  std::copy_if(data.begin(),data.end(),std::inserter(elements,elements.begin()),[character](std::string str){return str[0]==character;});
  return elements;
}

class Compare{
 private:
  char character_;
 public:
  Compare(char character):character_(character){};
  bool operator() (const std::string& element){
    return(element[0]==character_);
  }
};

std::list<std::string> FindByLetterObject(const char& character,std::list<std::string> data){
  std::list<std::string> elements;
  Compare compare(character);
  std::copy_if(data.begin(),data.end(),std::inserter(elements,elements.begin()),compare);
  return elements;
};

void DeleteByLetter(const char& character,std::list<std::string>& data){
  auto iterator=std::find_if(data.begin(),data.end(),
                             [character](std::string str){return str[0]==character;});
  if(iterator==data.end()){
    return;
  }
  while(iterator!=data.end()){
    data.erase(iterator);
    iterator=std::find_if(iterator++,data.end(),
                          [character](std::string str){return str[0]==character;});
  }
}

int AmountOfWords(const char& character,std::list<std::string>& data){
  int i=0;
  auto iterator=std::find_if(data.begin(),data.end(),
                             [character](std::string str){return str[0]==character;});
  while(iterator!=data.end()){
    i+=1;
    auto iterator=std::find_if(data.begin(),data.end(),
                               [character](std::string str){return str[0]==character;});
  }
  return i;
}

void Reverse(const std::list<std::string>& data,std::string filename){
  std::ofstream out(filename);
  std::reverse_copy(data.begin(),data.end(),std::ostream_iterator<std::string>(out," "));
}

std::vector<std::string> DifferentWords(std::string filename){
  std::string word;
  std::ifstream in(filename);
  std::set<std::string> dif_words;
  while(in>>word){
    dif_words.insert(word);
  }
}

std::map<std::string,int> WordFrequency(std::string filename){
  std::map<std::string,int> frequency;
  std::ifstream in(filename);
  std::vector<std::string> words;
  std::string word;
  while(!in.eof()){
    in>>word;
    words.push_back(word);
  }
  for(std::string str:words){
    int amount=std::count_if(words.begin(),words.end(),[str](const std::string& word){return str==word;});
    frequency.insert(std::make_pair(str,amount));
  }
  return frequency;
}

class MyClass{
 private:
  int id;
  int number1_;
  int number2_;
  int number3_;
 public:
  MyClass()=default;
  MyClass(int number1,int number2,int number3):number1_(number1),number2_(number2),number3_(number3){}
  ~MyClass()=default;
  int GetNumber1() const {return number1_;}
  int GetNumber2() const {return number2_;}
  int GetNumber3() const {return number3_;}
  int GetId() const {return id;}
  bool operator<(MyClass obj) {
    return (id < obj.GetId());
  }
  };

struct SortByOneParameter{
  bool operator()(const MyClass& obj1,const MyClass& obj2){
    return obj1.GetNumber1()<obj2.GetNumber1();
  }
};

struct SortByTwoParameter{
  bool operator()(const MyClass& obj1,const MyClass& obj2){
    if(obj1.GetNumber1()==obj2.GetNumber1()){
      return obj1.GetNumber2()<obj2.GetNumber2();
    }
    return obj1.GetNumber1()<obj2.GetNumber1();
  }
};

struct SortByThreeParameter{
  bool operator()(const MyClass& obj1,const MyClass& obj2){
    if(obj1.GetNumber1()==obj2.GetNumber1()){
      if(obj1.GetNumber2()==obj2.GetNumber2()){
        return obj1.GetNumber3()<obj2.GetNumber3();
      }
      return obj1.GetNumber2()<obj2.GetNumber2();
    }
    return obj1.GetNumber1()<obj2.GetNumber1();
  }
};
std::vector<MyClass>data_;
SortByOneParameter compare1;
std::sort(data_.begin,data_.end(),compare1);

std::istream& operator>>(std::istream& in,std::list<std::string> data_list){
  std::istream_iterator<std::string> input(in);
  std::string str;
  while(in>>str){
    data_list.push_back(*input);
    input++;//пробел
  }

}
std::ostream& operator<<(std::ostream& out, std::list<std::string> data_list){
  std::ostream_iterator<std::string> output(out);
  std::copy(data_list.begin(), data_list.end(),
            std::ostream_iterator<std::string>(out, " "));
  }


#endif //INC_15_02__WORKWITHDATA_H_
