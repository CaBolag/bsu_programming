#include<iostream>
extern "C" void _stdcall ChangeRowCalm(int* a, int size, int index);
extern "C" int _stdcall LongestSeq(char* str, char* lengthSeq);

//void ChangeRowCalm(int* a, int N, int index) {
//	_asm {
//		xor ecx,ecx
//	cycle:
//		mov eax, N
//			imul ecx
//			add eax, index
//			mov edi, eax; index in colmn
//
//			mov eax, N
//			imul index
//			add eax, ecx
//			mov esi, eax; index in row
//
//			mov edx, a
//			mov eax, [edx][esi * 4]
//			mov ebx, [edx][edi * 4]
//			mov[edx][esi * 4], ebx; swap
//			mov[edx][edi * 4],eax
//			
//			inc ecx
//			mov eax,N
//			cmp ecx,eax
//			jl cycle
//	}
//}

int main() {
	/*int size, index;
	std::cout << " Enter Matrix size\n";
	std::cin >> size;
	std::cout << " Enter index\n";
	std::cin >> index;
	int* A = new int[size * size];
	for (size_t i = 0; i < size * size; i++)
	{
		std::cin >> A[i];
	}
	ChangeRowCalm(A, size, index);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
			std::cout << A[i * size + j] << " ";
		std::cout << "\n";
	}*/

	char str[] = "aabbbb ccd", len = 0;
	int i = LongestSeq(str, &len);
	std::cout << "start of seq= " << i << " lenght of seq=" << static_cast<int>(len) << std::endl;

	return 0;
}