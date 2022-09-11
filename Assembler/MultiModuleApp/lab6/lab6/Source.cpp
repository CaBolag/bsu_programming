#include<iostream>
extern "C" int _fastcall ZeroZone(int* arr,int size);
extern "C" void _fastcall Replace(int* arr, int size);
extern "C" int _stdcall IsPerfect(int number);
extern "C" int _stdcall IsPrime(int number);
extern "C" int _stdcall IsPrime(int number);
extern "C" int _stdcall DeleteDigits(int number);


int main() {
	{
		//lab5 task1
		int size = 10;
		int zones = 0;
		int* arr = new int[size] {1, 0, 1, 0, 0, 0, 1, 1, 0, 0 };
		zones = ZeroZone(arr, size);
		std::cout << zones<<std::endl;
	}

	{
		//lab5 task2
		size_t size = 6;
		int* arr = new int[size] {10, 100, 1, 2, 3, 4};
		Replace(arr, size);
		for (size_t i = 0; i < size; i++) {
			std::cout << arr[i] << "\n";
		}
	}

	{
		//lab4 task1
	    std::cout << "Enter the number:";
	    int number,sum=0,flag_perfect=0,flag_prime=0;
	    std::cin >> number;
		flag_perfect = IsPerfect(number);
		flag_prime = IsPrime(number);

		if (flag_perfect) {
			std::cout << "The number is perfect\n";
		}
		else {
			std::cout << "The number isn't perfect\n";
		}
		if (flag_prime) {
			std::cout << "The number is prime\n";
		}
		else {
			std::cout << "The number isn't prime\n";
		}
	}
	//lab4 task3
	{
		std::cout << "Enter the number:";
		int num, new_num = 0, power = 1;
		std::cin >> num;
		new_num = DeleteDigits(num);
		std::cout << "New number: " << new_num;
	}
	return 0;
}



