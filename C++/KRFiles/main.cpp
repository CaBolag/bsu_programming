#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <ostream>
#include <iterator>
std::string ConsoleReader(std::string);
bool IsNonIncreasingOrder(std::string);
std::vector<std::string>FileReader(std::string);
std::vector<std::string> WordParser(std::vector<std::string> &);
std::vector<std::string> FindItems(std::vector<std::string> &);
int WordWeight(std::string);
int WordWeight(std::vector<std::string> &);
template <typename T>
void FileWriter(T &);
void SortCollection(std::vector<std::string> &);
void Encryption(std::string, std::string);
int main() {
    std::string input_file=ConsoleReader("Enter input file:");
    std::vector<std::string> input_data =FileReader(input_file);
    std::vector<std::string>input_words=WordParser(input_data);
    std::vector<std::string> right_words=FindItems(input_words);
    SortCollection(right_words);
    std::map<std::string,int> word_weight_map;
    for(int i=0;i<right_words.size();i++){
        word_weight_map.insert(std::make_pair(right_words[i],WordWeight(right_words[i])));
    }
    FileWriter(word_weight_map);
    return 0;
}

std::string ConsoleReader(std::string msg){
    std::cout<< msg;
    std::string str;
    std::cin>>str;
    return str;
}
bool IsNonIncreasingOrder(std::string str) {
    int size = str.size();
    for (int i = size - 1; i > 1; i -= 2) {
        if (str[i] < str[i - 2]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string>FileReader(std::string input_file) {
    std::ifstream in(input_file);
    std::vector<std::string> input_data;
    if (in) {
        std::string str;
        while (!in.eof()) {
            getline(in, str);
            input_data.push_back(str);
        }
    }
    return input_data;
}
std::vector<std::string> WordParser(std::vector<std::string> &lines) {
    std::vector<std::string> V;
    for (int i = 0; i < lines.size(); i++) {
        std::istringstream in(lines[i]);
        while(!in.eof()) {
            std::string str;
            in >> str;
            V.push_back(str);
        }
    }
    return V;
}

std::vector<std::string> FindItems(std::vector<std::string> &input_words){
    std::vector<std::string>right_words;
    for(int i=0;i<input_words.size();i++){
        if (IsNonIncreasingOrder(input_words[i])){
            right_words.push_back(input_words[i]);
        }
    }
    return right_words;
}

int WordWeight(std::string str) {
    int weight = 0;
    for (int i=0; i< str.size();i++) {
        int x=str[i];
        int y=str[i];
        x = x >> 2;
        y = y >> 4;
        if(x%2==1 && y%2==1){//если число нечетное, то младший бит=1
            weight+=int(str[i]);
        }
    }
    return weight;
}
int WordWeight(std::vector<std::string> &input_vector){
    int weight = 0;
    for (int i=0; i< input_vector.size();i++){
        std::string str=input_vector[i];
        for (int j=0; j< str.size();j++) {
            int x=str[j];
            int y=str[j];
            x = x >> 2;
            y = y >> 4;
            if(x%2==1 && y%2==1){//если число нечетное, то младший бит=1
                weight+=int(str[i]);
            }
        }
    }
    return weight;
}
template <typename T>
void FileWriter(T &input_map){
    std::ofstream out("C:\\Clion projects\\KR1_2020_3\\output_file.txt");
    for (std::map< std::string, int >::iterator it=input_map.begin(); it !=input_map.end();it++ )
    {
        out << it->first<<" "<<it->second << "\n";
    }
}
void SortCollection(std::vector<std::string> &input_vector) {

    for (int i = 0; i < input_vector.size(); i++) {
        for (int j = i; j > 0; j--) {
            if ([](int j,std::vector<std::string> input_vector) {
                return (WordWeight(input_vector[j]) < WordWeight(input_vector[j + 1])) ?
                       true : false;
            }) {
                std::swap(input_vector[j], input_vector[j + 1]);
            }
        }
    }
}
void Encryption(std::string file_path, std::string key){
    file_path.erase(file_path.size()-4);
    std::string new_file_path=file_path+"_encr.txt";
    std::ofstream out("C:\\Clion projects\\KR1_2020_3\\"+new_file_path);
}