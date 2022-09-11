//#include <iostream>
//
//int main() {
//	size_t Siz;
//	const size_t SizeS=5;
//	int sum = 0;
//	int arr[] = { 1,6,8,6,1 };
//	std::cout << "Enter Size\n";
//	std::cin >> Siz;
//	int* darr = new int[Siz];
//	for (size_t i = 0; i < Siz; i++) {
//		darr[i] = i;
//	}
//	_asm {
//		mov eax, 0
//		lea ebx, arr; proper static array load
//		mov ecx,SizeS
//		repeat:
//		add eax, dword ptr[ebx]; load value by address
//			add ebx,4
//			loop repeat
//			mov sum,eax
//	}
//	std::cout << sum<<"\n";
//	_asm {
//		mov eax, 0
//		mov esi, darr; proper dynamic array load
//		mov ecx, Siz
//		_repeat :
//		add eax, dword ptr[esi]; load value by address
//			add esi, 4
//			loop _repeat
//			mov sum, eax
//	}
//	std::cout << sum << "\n";
//
//	int flag = 1;
//	_asm {
//		mov eax, SizeS
//
//		mov ecx, 2
//		cdq
//		div ecx
//		mov ecx, eax;amount of repeating
//
//		mov eax, SizeS
//		dec eax
//		lea ebx, arr
//		lea esi,arr
//		mov edx, [ebx][eax * 4]; value of arr[size - 1]
//
//		repeat:
//		cmp [ebx],edx
//			jne not_polindrom
//			dec eax
//			mov edx, [esi][eax * 4]
//			add ebx, 4
//			loop repeat
//			jmp the_end
//			not_polindrom:
//		mov flag,0
//			the_end:
//	}
//	if (flag) {
//		std::cout << "The number is a polindrom\n";
//	}
//	else {
//		std::cout << "The number isn't a polindrom\n";
//	}
//	return 0;
//}