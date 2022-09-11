
#include <gtest/gtest.h>
#include "StringProcessing.h"
#include "StringProcessing.cpp"

TEST(TestFunction,strchr_cstr){
  char str[]="asdfg";
  int ch='d';
  char excepted[]="dfg";
  char* new_str;
  StringProcessing::strchr(str,ch,new_str);
  EXPECT_STREQ(new_str,excepted);
}

TEST(TestFunction,strchr_str){
  const std::string str="asdfg";
  int ch='f';
  std::string excepted="fg";
  std::string new_str;
  StringProcessing::strchr(str,ch,new_str);
  EXPECT_EQ(new_str,excepted);
}

TEST(TestFunction,compact_cstr){
  char str[]="as    df  g";
  char excepted[]="as df g";
  char* compacted_str;
  StringProcessing::compact(str,compacted_str);
  EXPECT_STREQ(compacted_str,excepted);
}
TEST(TestFunction,compact_str){
  std::string str="as   df g";;
  std::string excepted="as df g";
  StringProcessing::compact(str);
  EXPECT_EQ(str,excepted);
}

TEST(TestFunction,deleteWord_cstr){
  char str[]="as df g";
  char del_str[] ="df";
  char excepted[]="as g";
  char* deleted;
  StringProcessing::deleteWord(str,del_str,deleted);
  EXPECT_STREQ(deleted,excepted);
}

TEST(TestFunction,deleteWord_str){
  std::string str="as   df g";;
  std::string del_str="df";
  std::string excepted="as g";
  StringProcessing::deleteWord(str,del_str);
  EXPECT_EQ(str,excepted);
}

TEST(TestFunction, theLongest_cstr){
  char str[] = "a aaa aa a";
  char excepted[]="aaa";
  char* the_longest;
  StringProcessing::theLongest(str,the_longest);
  EXPECT_STREQ(the_longest,excepted);
}

TEST(TestFunction, theLongest_str){
  std::string str="a aaa aa a";
  std::string excepted="aaa";
  std::string the_longest;
  StringProcessing::theLongest(str,the_longest);
  EXPECT_EQ(the_longest,excepted);
}


TEST(TestFunction,reverse_cstring){
  char str[]="ab Abc bA";
  char rev_str[]="ba cbA Ab";
  char* reversed;
  StringProcessing::reverse(str,reversed);
  EXPECT_STREQ(reversed,rev_str);
}
