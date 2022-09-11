//#include<iostream>
//int main() {
//	/*int fact = 1,value;
//	std::cin >> value;
//	_asm {
//		mov eax, fact
//		mov ecx, value
//		factorial:
//		mul ecx
//			loop factorial
//			mov fact,eax
//	}
//	std::cout << fact<<"\n";*/
//
//
//	//int number,count=0;
//	//std::cin >> number;
//	////while (number != 0) {
//	////	count++;
//	////	number /= 10;
//	////}
//	//_asm {
//	//	mov eax,number
//	//	mov ecx,count
//	//	mov ebx,10
//	//	cmp eax,0
//	//	jnz begin_while
//	//	je end_while
//
//	//begin_while:
//	//	cmp eax, 0
//	//		je end_while
//	//		inc ecx
//	//		cdq
//	//		idiv ebx
//	//end_while:
//	//	mov count,ecx
//	//}
//	//std::cout << count;
//

	//int number,result=0;
	//std::cout << "Enter number:";
	//std::cin >> number;

	/*while (number > 0) {
		result = result * 10 + number % 10;
		number /= 10;
	}*/
	/*_asm {
		mov eax,number
		mov ecx,result
		mov ebx,10

		begin_while:
		cmp eax,0
			jg repeat
			je end_while

			repeat:
		imul ecx,ebx
			cdq
			idiv ebx
			add ecx,edx
			jmp begin_while

			end_while:
		mov result,ecx
	}*/
	/*std::cout << result;

	return 0;*/
