#include<iostream>
//extern "C" int _stdcall power(int a, int n);
extern "C" int _fastcall power(int a, int n);
extern "C" int _stdcall DelSubArray(int* arr,int* subArr, int size1, int size2);

int main() {
	int a,n;
	/*std::cout << "Enter the number and the power: ";
	std::cin >> a >> n;
	std::cout << power(a, n)<<std::endl;*/

	int size1=5, size2=3;
	int* arr = new int[size1] {1, 2, 3, 4, 5};
	int* subArr = new int[size2] {2,3, 4};
	DelSubArray(arr, subArr, size1, size2);
		for (size_t i = 0; i < size1 - size2; i++)
		{
			std::cout << arr[i] << " ";
		}
	return 0;
}