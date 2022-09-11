#include <iostream>
//extern "C" float* _stdcall FindSin(int n, float* x);
extern "C" double* _fastcall CalcSin(int n, double* x);
extern "C" void _stdcall FindZeroAmount(int* a, int rows, int columns,int* result);



int main() {
	{
		int rows, columns;
		std::cout << " Enter Matrix size\n";
		std::cin >> rows >> columns;
		std::cout << " Enter matrix:\n";
		int* matrix = new int[rows * columns];
		for (int i = 0; i < rows * columns; i++)
		{
			std::cin >> matrix[i];
		}
		int* result = new int[columns];
		FindZeroAmount(matrix, rows, columns, result);
		for (int i = 0; i < columns; i++)
		{
			std::cout << result[i]<<" ";
		}
		std::cout << "\n";
	}
	double x = 3.14;
	double* x_ptr = &x;
	double* result;
	int n = 10;
	//std::cout << *CalcSin(5,&x);
	double realsin;
	_asm {
		mov edx,x_ptr//указатель
		mov ecx,n
		call CalcSin
		mov result,eax//result - pointer
		fld qword ptr[edx]
		fsin
		fstp realsin
	}
	std::cout << *result<<"\n";
	std::cout << realsin << "\n";

	return 0;
}