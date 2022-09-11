#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

//extern "C" double* _stdcall CalcLn(int k);
//extern "C" double* _stdcall IntegralA(int k);
extern "C" double* _stdcall CalcLnX1(int k, int x);
extern "C" double* _stdcall IntegralB(int k);


int main() {
	int k;
	std::cin >> k;

	//std::cout << *CalcLn(k) << "\n";
	std::cout << M_LN2 << "\n";
	std::cout << *CalcLnX1(k,1) << "\n";

	//std::cout << *IntegralA(k) << "\n";
	std::cout << *IntegralB(k) << "\n";


	return 0;
}