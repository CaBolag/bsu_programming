#include <iostream>
extern "C" double* _fastcall CalculateCos(int N, float* delta);
extern "C" void _cdecl CreateVectorB(int matrix[][2], int rows, int columns, int* B);



int main() {
	{

	/*	float delta;
		double* cos;
		int n = 5;
		_asm {
			mov ecx,5
			lea edx,delta
			call CalculateCos
			mov cos,eax
		}
		std::cout << delta << "\n";*/

		float delta = 0;
		std::cout << "cos pi/4="<<*CalculateCos(5, &delta) << "\n";
		std::cout << "delta="<<delta << "\n"; 


	}


	{//task 2
		int rows=2, columns=3;
		int matrix[3][2];
		std::cout << "Enter Matrix" << std::endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cin >> matrix[i][j];		}
		}

		int* B = new int[columns];
		CreateVectorB(matrix, rows,columns, B);
	
		for (int i = 0; i < columns; i++) {
			std::cout << B[i]<<" ";
		}
	}


	//_asm {
	//	mov [esp + 4], matrix
	//	mov[esp + 8], rows
	//	mov[esp + 12], columns
	//	mov[esp + 16], B
	//	call CreateVectorB
	//}



	return 0;
}