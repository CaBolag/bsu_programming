#include "testing.h"
std::vector<std::string> File_reader(std::string file_name) {
    std::ifstream in(file_name);
    std::vector<std::string> Strings;
    if (!in.is_open())
    {
        std::cout << "Error file open\n";
    }
    std::string str;
    while (!in.eof()) {
        getline(in, str);
        Strings.push_back(str);
    }
    return Strings;
}

std::vector<std::string> DeleteElements(std::ifstream &in, std::string delete_word) {
    std::string str;
    std::vector<std::string> Strings;
    in.seekg(0, std::ios::beg);
    while (!in.eof()) {
        getline(in, str);
        int position = 0;
        while (position != std::string::npos) {
            position = str.find(delete_word, position);
            if (position == std::string::npos) {
                break;
            } else {
                str.erase(position, delete_word.length());
                position++;
            }
        }
        Strings.push_back(str);
    }
    return Strings;
}

std::vector<std::string> Sort_strings(std::string file_name) {
    std::vector<std::string> Strings=File_reader(file_name);
    std::sort(begin(Strings), end(Strings), [&](const std::string& elem1, const std::string& elem2)
    {return strcmpi(elem1.c_str(), elem2.c_str()) < 0; });
    return Strings;
}

void File_output(std::vector<std::string> strings,std::string file_name){
    std::ofstream fout(file_name);
    for(std::string str:strings){
        fout<<str;
    }
}

