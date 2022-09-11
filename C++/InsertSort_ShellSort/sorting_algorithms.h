#ifndef PRACTICE_4_5_2_SORTING_ALGORITHMS_H
#define PRACTICE_4_5_2_SORTING_ALGORITHMS_H

#include <vector>
void Sort_and_time(std::string, std::ifstream &, std::ofstream &);
//Считывает данные из файла,
//выполняет указанную сортировку, высчитывает время выполнения алгоритма,
// заносит данные о выполнении в файл вывода

extern int compare,swap;
template<typename T,typename S>
void InsertSort(T &array, S size){
    for(int i=1;i<size;i++) {
        for (int j=i;j>0;j--){
            compare++;
            if(array[j-1]>array[j]){
                int tmp=array[j-1];
                array[j-1]=array[j];
                array[j]=tmp;
                swap++;
            }
        }
    }
    std::cout<<"The number of compare:"<<compare<<std::endl;
    std::cout<<"The number of swap:"<<swap<<std::endl;
}
template<typename T,typename S>
void ShellSort(T &array,S size) {
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++) {
            tmp = array[i];
            for (j = i; j >= step; j -= step) {
                compare++;
                if (tmp < array[j - step]) {
                    array[j] = array[j - step];
                    swap++;
                }
                else
                    break;
            }
            array[j] = tmp;
        }
    std::cout<<"The number of compare:"<<compare<<std::endl;
    std::cout<<"The number of swap:"<<swap<<std::endl;
}
#endif //PRACTICE_4_5_2_SORTING_ALGORITHMS_H
