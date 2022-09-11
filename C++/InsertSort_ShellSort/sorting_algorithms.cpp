#include <iostream>
#include <chrono>
#include<ctime>
#include "sorting_algorithms.h"
#include <ostream>
#include <fstream>
#include <vector>
void Sort_and_time(std::string type_sort,std::ifstream &in, std::ofstream &out){
    std::vector<int> data;
    int num;
    while (!in.eof()){
        in>>num;
        data.push_back(num);
    }
    int size=data.size();
    out<<"The number of elements is"<<size<<std::endl;
    size-=1;
    if (type_sort=="InsertSort"){
        out << "InsertSort"<<std::endl;
        auto start = std::chrono::system_clock::now();
        InsertSort(data,size);
        auto end = std::chrono::system_clock::now();
        auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        out << "Calculations are finished on " << std::ctime(&end_time)<<"\n"
            << "InsertSort Algorithm execution time: " << elapsed_milliseconds << "ms" << std::endl;
    }
    else{
        out << "ShellSort"<<std::endl;
        auto start = std::chrono::system_clock::now();
        ShellSort(data,size);
        auto end = std::chrono::system_clock::now();
        auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        out << "Calculations are finished on " << std::ctime(&end_time)<<"\n"
            << "InsertSort Algorithm execution time: " << elapsed_milliseconds << "ms" << std::endl;
    }
}

