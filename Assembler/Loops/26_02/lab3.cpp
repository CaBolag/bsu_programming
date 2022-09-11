#include<iostream>
int main() {
	//task1
	/*	int number, sum = 0, even_amount = 0,reverse=0;
		std::cout << "Enter number:";
		std::cin >> number;*/
		/*_asm {
			mov eax, number
			mov ebx, 10
			cmp eax, 0
			jnz begin_while
			je end_while
			begin_while:
			cmp eax, 0
				je end_while
				cdq
				idiv ebx
				add sum, edx
				jmp begin_while
				end_while :
		}
		std::cout << sum;*/
		//	_asm {
		//		mov ebx, number
		//		cmp ebx, 0
		//		jnz begin_while
		//		je end_while
		//		begin_while :
		//		mov ebx, number
		//			cmp ebx, 0
		//			je end_while
		//		
		//	        mov eax,ebx
		//				mov ebx, 10
		//				cdq
		//			idiv ebx
		//			mov number,eax
		//			mov eax, edx
		//				cmp eax,0
		//				je _zero
		//				mov ebx, 2
		//				cdq
		//			idiv ebx
		//			cmp edx, 0
		//			je _even
		//			_zero :
		//			jmp begin_while
		//			_even :
		//		add even_amount, 1
		//			jmp begin_while
		//			end_while :
		//	}
		//	std::cout<<even_amount;
		//}

		/*_asm {
			mov eax, number
			mov ecx, reverse
			mov ebx, 10

			begin_while:
			cmp eax, 0
				jg repeat
				je end_while

				repeat :
			imul ecx, ebx
				cdq
				idiv ebx
				add ecx, edx
				jmp begin_while

				end_while :
			mov eax,number
			cdq
				idiv ecx
				mov reverse,edx
		}
		if (reverse == 0) {
			std::cout << "The number is symmetrical";
		}
		else {
			std::cout << "The number is not symmetrical";
		}*/




		//task2
		//	int _numer, _denom, numer, denom;
		//	std::cin >> _numer>> _denom;
		//	_asm {
		//		mov eax, _numer
		//		mov numer,eax
		//		mov eax, _denom
		//		mov denom,eax
		//		begin_while :
		//		mov eax,denom
		//		cmp eax, 0
		//			je end
		//			mov eax, numer
		//			mov ebx, denom
		//			cdq
		//			idiv ebx
		//			mov denom, edx
		//				mov numer, ebx
		//				jmp begin_while
		//				end :
		//			mov ebx, numer
		//				mov eax, _numer
		//				cdq
		//				idiv ebx
		//				mov _numer, eax
		//				mov eax, _denom
		//				cdq
		//				idiv ebx
		//				mov _denom, eax
		//	}
		//	std::cout << _numer<<" "<<_denom;
		//}




	//task3
	/*int number, power,result=1;
	std::cin >> number >> power;
	_asm {
		mov power, ecx
		mov eax, result
		_power:
		mov edx, number
		mul edx
			loop _power
			mov result,eax
	}
	std::cout << result;
}*/

//task4
	int number, power=0;
	std::cout << "Enter number:";
	std::cin >> number;
	_asm {
		mov eax,number
		mov ecx,2
		mov ebx,power
		division:
		cmp eax, 0
			je end
			cdq
			idiv ecx
			inc ebx
			jmp division
			end:
		mov power,ebx
	}
	std::cout <<"The number is located between "<< power-1 <<" and "<< power<<" powers of 2";
}