
#include"data_generation.h"
#include <iostream>
#include <algorithm>
#include <vector>
void RandomNumbers(std::ofstream &out,int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        num = rand() % 100;
        out << num;
    }
}
void AscendingNumbers(std::ofstream &out,int size){
    std::vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        nums[i]= rand() % 100;
    }
    std::sort(nums.begin(), nums.end());
    for(int i=0;i<size;i++){
        out<<nums[i];
    }
}

void DescendingNumbers(std::ofstream &out,int size) {
    std::vector<int> nums;
    for (int i = 0; i < size; i++) {
        nums[i] = rand() % 100;;
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (int i = 0; i < size; i++) {
        out << nums[i];
    }
}



