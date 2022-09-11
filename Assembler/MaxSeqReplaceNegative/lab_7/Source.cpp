#include <iostream>
extern "C" int _stdcall MaxSeq(int* arr,int arr_size, int* seq_size);
extern "C" void _stdcall ReplaceNegative(int* arr, int arr_size);

int main(){
	{
		int size;
		std::cout << "Enter size:";
		std::cin >> size;
		int* arr = new int[size - 1];
		std::cout << "Enter array:";
		for (int i = 0; i < size; i++)
		{
			std::cin >> arr[i];
		}
		int seq_size = 0;
		int start_seq = MaxSeq(arr, size, &seq_size);
		std::cout << "Start of the max sequance is the element number " << start_seq << "\n";
		std::cout << "Length of the max seq is  " << seq_size << "\n";
	}

	{
		int size;
		std::cout << "Enter size:";
		std::cin >> size;
		int* arr = new int[size - 1];
		std::cout << "Enter array:";
		for (int i = 0; i < size; i++)
		{
			std::cin >> arr[i];
		}
		ReplaceNegative(arr, size);
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i]<<" ";
		}
	}

	return 0;
}