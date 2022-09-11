#include <iostream>  
int main() {
	{//task1
		std::cout << "Enter amount of seconds: " << std::endl;
		int amount, hour, min, sec;
		std::cin >> amount;
		_asm {
			mov eax, amount
			mov ecx, 3600
			cdq
			div ecx
			mov hour, eax

			mov eax, edx
			mov ecx, 60
			cdq
			div ecx
			mov min, eax
			mov sec, edx
		}
		std::cout <<"hours:" <<hour <<" min:" <<min <<" sec:"<< sec << "\n";
	}

	{
		//task2
		int a, b, c, result = 0;
		std::cout << "Enter numbers:";
		std::cin >> a >> b >> c;
		_asm {
			mov eax, a
			mov ecx, 2
			cdq
			div ecx
			cmp edx, 0
			je divided1
			divided1 :
			mov eax, a
				add result, eax

				mov eax, b
				mov ecx, 2
				cdq
				div ecx
				cmp edx, 0
				je divided2
				divided2 :
			mov eax, b
				add result, eax

				mov eax, c
				mov ecx, 2
				cdq
				div ecx
				cmp edx, 0
				je divided3
				divided3 :
			mov eax, c
				add result, eax

		}
		std::cout <<"Sum:"<< result << "\n";
	}

	{
		//task3
		int year, amount;
		std::cin >> year;
		_asm {
			mov eax, year
			mov ecx,100
			cdq
			div ecx
			cmp eax, 0
			je divided_100
			jne not_divided_100
			divided_100 :
			jmp divided_4_
				not_divided_100 :
			jmp divided_400_
				divided_400_ :
			mov eax, year
				mov ecx,400
				cdq
				div ecx
				cmp eax, 0
				je not_leap
				jne divided_4_
				divided_4_ :
			mov eax, year
				mov ecx,4
				cdq
				div ecx
				cmp eax, 0
				je leap
				jne not_leap
				leap :
			mov amount, 366
				not_leap :
				mov amount, 365
		}
		std::cout << amount;

	}


	return 0;
}