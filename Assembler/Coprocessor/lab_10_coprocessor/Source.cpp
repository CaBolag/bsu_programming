#include<iostream>

extern "C" float* _stdcall PowerFunction(float a, float x);
extern "C" int* _stdcall FindRoots(int a, int b, int c, int root_2);
int main() {
	{
		double a,x;
		std::cout << "Enter the number: ";
		std::cin >> a;
		std::cout << "Enter the power: ";
		std::cin >> x;
		std::cout << "\n" << a << "^" << x << "=" << *PowerFunction(a, x);
	}
	{
	    std::cout << "Enter a,b,c: ";
		int a, b, c;
		std::cin >> a >> b >> c;
		int root_2 = 0;
		std::cout << "\nRoots: " << *FindRoots(a, b, c, root_2) << " " << root_2;
	}

	return 0;
}