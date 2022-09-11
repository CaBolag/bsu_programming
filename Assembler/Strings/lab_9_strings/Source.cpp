#include<iostream>

extern "C" int _stdcall FindShortest(char* str, int len);
extern "C" int _stdcall FindWord(char* str, int str_len, char* word, int word_len );

int main() {
	{
		char str[] = "aaa aa aaaa";
		int len = strlen(str);
		int short_len = FindShortest(str, len);//2
		std::cout << short_len << std::endl;
	}
	{
		char str[] = "a c bb c def";
		int str_len = strlen(str);
		char word[] = "bb";
		int word_len = strlen(word);
		int start_element = FindWord(str, 10, word, 2);//5
		std::cout << start_element << std::endl;

	}


	return 0;
}