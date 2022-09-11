#include<iostream>
extern "C" int _fastcall FindLenth(char* str);

int main() {
	int size;
	std::cout << "Enter size:";
	char str[]="abcdef";

	int lenth = FindLenth(str);
	std::cout << lenth;
	return 0;
}
xor eax, eax
mov esi, ecx
mov edi, '\0'
_lenth:
cmpsb
je _end
inc eax
inc edi
jmp _lenth

_end :
ret 4