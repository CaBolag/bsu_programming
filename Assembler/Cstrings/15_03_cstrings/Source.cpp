#include<iostream>

extern "C" int _fastcall FindLength(char* str);
extern "C" int _stdcall FindPositionOnLeft(char* str,char element);
extern "C" int _stdcall FindPositionOnRight(char* str, char element);
extern "C" void _stdcall FindSubstring(char* str, int position, int length,char* substring);



int main() {
	{
		char str[] = "abcdef";
		int lenth = FindLength(str);
		std::cout << lenth<<std::endl;
	}
	{
		char str[] = "abcdef";
		char element = 'd';
		
		int left_position = FindPositionOnLeft(str, element);
		std::cout << left_position<<std::endl;//3

		int right_position = FindPositionOnRight(str, element);
		std::cout << right_position<<std::endl;//4

	}
	{
		char str[] = "aa cccc dd";

		int position = 3;
		const int lenght = 4;
		char substring[5]="\0";
		FindSubstring(str,position,lenght,substring);
		std::cout << substring;//cccc
	}

	return 0;
}