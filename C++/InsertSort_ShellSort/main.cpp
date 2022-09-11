#include <iostream>
#include<ctime>
#include "sorting_algorithms.h"
#include "data_generation.h"
#include <ostream>

int compare=0,swap=0;
int main() {
    srand(static_cast<size_t>(time(0)));
    for (int i = 10; i < 10000; i *= 10) {
        std::string str = std::to_string(i);
        std::ofstream random_1("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_1.txt");
        RandomNumbers(random_1, i);
        std::ofstream random_2("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_2.txt");
        RandomNumbers(random_2, i);
        std::ofstream random_3("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_3.txt");
        RandomNumbers(random_3, i);
        std::ofstream ascending("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_ascending.txt");
        AscendingNumbers(ascending, i);
        std::ofstream descending("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_descending.txt");
        DescendingNumbers(descending, i);
    }
    std::ofstream out("C:\\Clion projects\\practice\\practice 4-5_2\\output.txt");
    for (int i = 10; i < 10000; i *= 10) {
        std::string str = std::to_string(i);
        std::ifstream random_1_in("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_1.txt");
        Sort_and_time("InsertSort", random_1_in, out);
        Sort_and_time("ShellSort", random_1_in, out);
        std::ifstream random_2_in("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_2.txt");
        Sort_and_time("InsertSort", random_2_in, out);
        Sort_and_time("ShellSort", random_2_in, out);
        std::ifstream random_3_in("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_random_3.txt");
        Sort_and_time("InsertSort", random_3_in, out);
        Sort_and_time("ShellSort", random_3_in, out);
        std::ifstream ascending_in("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_ascending.txt");
        Sort_and_time("InsertSort", ascending_in, out);
        Sort_and_time("ShellSort", ascending_in, out);
        std::ifstream descending_in("C:\\Clion projects\\practice\\practice 4-5_2\\input_" + str + "_descending.txt");
        Sort_and_time("InsertSort", descending_in, out);
        Sort_and_time("ShellSort", descending_in, out);
    }
        return 0;
    }
