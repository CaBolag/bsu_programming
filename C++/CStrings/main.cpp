#include <iostream>
#include <string.h>
#include "StringProcessing.h"
#include "StringProcessing.cpp"

int main() {

/*

  char str[]="asdfg";
  int ch='d';
  char excepted[]="dfg";
  char* str_=process.strchr(str,ch);
  bool flag=1;
  for (int kI = 0; kI < strlen(str_); ++kI) {
    if(*str_!=excepted[kI]){
      flag=0;
    }
    str_++;
  }
  if(flag) {
    std::cout <<"True" ;
  };
*/

/*std::string str="asdfg";
int ch='f';
std::string str_=process.strchr(str,ch);;
std::string excepted="fg";
if(str_==excepted) {
  std::cout << "True";
}
return 0;*/





/*  char str[]="as df g";
  char del_str[]="df";
  process.deleteWord(str,del_str);
  std::cout<<str;*/

/*  char str[]="as   df g";
  process.compact(str);
  std::cout<<str;*/

 /* char str[]="as df g";
  char replaced_str[] ="df";
  char new_str[]="gh";
  char* new_=StringProcessing::replace(str,replaced_str,new_str);
  std::cout<<new_;*/


/*
  std::string str="as df g";
  std::string del_str="df";
  process.deleteWord(str,del_str);
  std::cout<<str;
*/


/*std::string str="a aaa aa a";
std::cout<<process.theLongest(str);*/


   char str[] = "a aaa aa a";
   char* theLongest;
   StringProcessing::theLongest(str,theLongest);
   std::cout<<theLongest;

 /* char str[]="ab Abc bA";
  std::cout<<process.reverse(str);*/
  return 0;
}