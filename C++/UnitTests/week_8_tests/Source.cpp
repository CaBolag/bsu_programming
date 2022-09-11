#include<string>
#include <vector>
#include<fstream>

std::vector<std::string> File_reader(std::string file_name) {
	std::ifstream in(file_name);
	std::string str;
	std::vector<std::string> Strings;
	while (!in.eof()) {
		getline(in, str);
		Strings.push_back(str);
	}
}
int main() {
	File_reader("input.txt");
	return 0;
}