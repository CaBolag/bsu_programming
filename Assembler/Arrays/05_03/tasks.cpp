#include<iostream>

int main() {
	//task1
	//const size_t SizeS=10;
	//int zero_zone=0;
	//int arr[] = { 1,0,1,0,0,0,1,1,0,0 };
	//_asm {
	//	mov ecx,SizeS
	//	//dec ecx
	//	mov edx,zero_zone
	//	lea ebx, arr
	//	repeat:
	//	cmp dword ptr[ebx],0
	//		je _zero
	//		jne _not_zero
	//		_zero:
	//	inc edx
	//		mov esi, dword ptr[ebx]
	//		add ebx, 4
	//		cmp esi, dword ptr[ebx]
	//		je _next
	//		jne _the_end
	//		_next:
	//	    dec ecx
	//	    mov esi, dword ptr[ebx]
	//		add ebx, 4
	//		cmp esi, dword ptr[ebx]
	//		je _next
	//		jne _the_end
	//		
	//_not_zero:
	//	add ebx,4
	//		loop repeat
	//		_the_end:
	//		loop repeat
	//		mov zero_zone,edx
	//}
	//std::cout << zero_zone;


	//task2
	//size_t Siz;
 //   std::cout << "Enter Size\n";
	//std::cin >> Siz;
	//int* darr = new int[Siz];
	//darr[0] = 10;
	//darr[1] = 100;
	//for (size_t i = 2; i < Siz; i++) {
	//	darr[i] = i;
	//}



	//_asm{
	//	mov esi, darr
	//	mov ebx, darr;max element
	//	mov ecx, Siz
	//	dec ecx
	//	repeat:
	//	add esi, 4
	//		mov edx, [esi]
	//	    cmp edx,[ebx]
	//		jg _greater
	//		loop repeat
	//		jmp _end
	//		_greater:
	//	mov ebx,esi
	//		loop repeat

	//		_end:
	//		mov ecx,dword ptr [esi]
	//		mov eax, dword ptr [ebx]
	//		mov dword ptr[esi],eax
	//		mov dword ptr[ebx],ecx
	//}
	//
	//for (int i = 0; i < Siz; i++) {
	//	std::cout << darr[i] << "\n";
	//}


	//task3
	int n = 8;
	int* arr = new int[n];
	
	for (size_t i = 0; i < n; i++) {
		arr[i] = i;
	}
	arr[5] = 6;
	int freq[100] = { 0 };//индекс массива freq-значения массива arr, значение freq-количество вхождений элемента i в arr
	int diff_el = 0;
	int biggest_freq = 0;
	_asm {
		xor ecx, ecx
		mov esi, arr
		lea edi, freq
		cycle :
		mov eax, [esi][ecx * 4]
			inc[edi][eax * 4]
			mov ebx, [edi][eax * 4]
			cmp ebx, 1
			jne same_el
			inc diff_el
			same_el :
		cmp ebx, biggest_freq
			jle lower_freq
			mov biggest_freq, ebx
			lower_freq :
		inc ecx
			cmp ecx, n
			jl cycle
	}
	std::cout << diff_el<<std::endl;
	for (int i = 0; i < 10; i++) {
		if (freq[i] == biggest_freq) {
			std::cout << '[' << i << '], ';
		}
	}
	return 0;
}