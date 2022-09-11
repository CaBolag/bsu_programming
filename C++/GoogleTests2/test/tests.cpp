
#include <gtest/gtest.h>
#include "testing.h"
#include "testing.cpp"

TEST(TestFunction, File_reader_1){
    std::string file_name="C:\\Clion projects\\Guseinova\\week_8_google_tests\\input.txt";
    std::vector<std::string> Strings_out={"ab","AB","ab","AB"};
    EXPECT_EQ( File_reader(file_name),Strings_out);
}


TEST(TestFunction,Delete_element_1){
    std::ifstream in("C:\\Clion projects\\Guseinova\\week_8_google_tests\\input.txt");
    std::vector<std::string> Strings_out={"","AB","","AB"};
    EXPECT_EQ(DeleteElements(in, "ab"),Strings_out);
}
TEST(TestFunction,Delete_element_2){
    std::ifstream in("C:\\Clion projects\\Guseinova\\week_8_google_tests\\input.txt");
    std::vector<std::string> Strings_out={"ab","AB","ab","AB"};
    EXPECT_EQ(DeleteElements(in, "a\n"),Strings_out); //"\n" т.к должно удалится целое слово, а не символы в слове
}

TEST(TestFunction,Sort_strings_1){
    std::string in("C:\\Clion projects\\Guseinova\\week_8_google_tests\\input.txt");
    std::vector<std::string> Strings_out={"ab","AB","ab","AB"};//не учитывает регистор, поэтому порядок слов не меняется
    EXPECT_EQ(Sort_strings(in),Strings_out);
}

TEST(TestFunction,Sort_strings_2){
    std::string in("C:\\Clion projects\\Guseinova\\week_8_google_tests\\input_1.txt");
    std::vector<std::string> Strings_out={"a","A","b","c"};
    EXPECT_EQ(Sort_strings(in),Strings_out);
}

TEST(TestFunction, File_reader_2){
    std::string file_name="C:\\Clion projects\\Guseinova\\week_8_google_tests\\input1.txt"; //файла input1.txt не существует
    std::vector<std::string> Strings_out; //пустой вектор
    EXPECT_EQ( File_reader(file_name),Strings_out);
}



