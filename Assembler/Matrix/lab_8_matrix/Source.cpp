#include <iostream>
extern "C" void _stdcall FindLocalMax(int* a, int amount_of_elements,int* local_maxs);
extern "C" int _stdcall FindRow(int* a, int rows,int columns);
int main() {
	{
		//task 1.1
		int rows, columns;
		std::cout << " Enter Matrix size\n";
		std::cin >> rows >> columns;
		std::cout << " Enter matrix:\n";
		int* matrix = new int[rows * columns];
		for (int i = 0; i < rows * columns; i++)
		{
			std::cin >> matrix[i];
		}
		int* local_maxs=new int[rows * columns];
		FindLocalMax(matrix, rows * columns, local_maxs);

	}
	{
		//task 2
		int rows, columns;
		std::cout << " Enter Matrix size\n";
		std::cin >> rows >> columns;
		std::cout << " Enter matrix:\n";
		int* matrix = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
		{
			std::cin >> matrix[i];
		}
		int row;
		row = FindRow(matrix, rows, columns);
	}
	return 0;
}
