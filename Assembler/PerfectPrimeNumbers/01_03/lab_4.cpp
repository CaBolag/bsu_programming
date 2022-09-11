#include <iostream>
int main() {

	//task1
	//std::cout << "Enter the number:";
	//int number,sum=0,flag_perfect=0,flag_prime=0;
	//std::cin >> number;
	//_asm {
	//	mov ebx,sum
	//	mov ecx,number
	//	dec ecx
	//	repeat:
	//	mov eax,number
	//	cdq
	//		div ecx
	//		cmp edx,0
	//		je divider
	//		loop repeat
	//		divider:
	//	mov eax, sum
	//		add eax, ecx
	//		mov sum, eax
	//		loop repeat
	//		mov eax, number
	//		mov ebx, sum
	//		cmp eax, ebx
	//		je perfect_num
	//		jmp _end
	//		perfect_num:
	//		mov flag_perfect,1
	//			_end:
	//	//task2
	//			cmp ebx,1
	//			je prime_num
	//			jmp the_end
	//			prime_num:
	//		mov flag_prime,1
	//			the_end:

	//}
	//if (flag_perfect) {
	//	std::cout << "The number is perfect\n";
	//}
	//else {
	//	std::cout << "The number isn't perfect\n";
	//}

	//if (flag_prime) {
	//	std::cout << "The number is prime\n";
	//}
	//else {
	//	std::cout << "The number isn't prime\n";
	//}

	//task3
	std::cout << "Enter the number:";
	int num,new_num=0,power=1;
	std::cin >> num;
	_asm {
		mov eax, num
		//mov ebx, 10
		cmp eax, 0
		jnz _begin
		je _end
		_begin :
		mov ebx, 10
			mov eax,num
		cmp eax, 0
			je _end
			cdq
			idiv ebx
			mov num,eax
			cmp edx,3
			jne not_3
			jmp _begin

			not_3:
		cmp edx, 6
			jne not_6
			jmp _begin

			not_6:
		mov num,eax
			mov eax,power
		imul edx,eax
		add new_num, edx
			imul eax,10
			mov power,eax
			jmp _begin
			_end:
	}
	std::cout << new_num;
	return 0;
}