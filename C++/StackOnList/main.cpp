#include <iostream>
#include <fstream>
#include <sstream>
#include "StackOnList.h"

int max(int a,int b) {
    return a>b?a:b;
}
int min(int a,int b) {
    return a<b?a:b;
}
//Задание 4. Использование стека для решения задач
//Вычислить значение формулы с min, max
//Пусть дана без ошибок формула, имеющая следующий синтаксис:
//<формула>::=<цифра> | max(<формула>, < формула >) | min (<формула>,< формула >)
//<цифра>::=0 1 2 3 4 5 6 7 8 9
//Например, 8 или max(4, min(3, 5)) или min(min(3, 5), max(2, max(3, 4))).
//Вычислить значение формулы, используя структуру данных стек.
int Result(std::string);

int main() {
    StackOnList<int> first;
    first.Push(5);
    std::cout<<first.Size()<<std::endl;//1
    std::cout<<first.Top()->value<<std::endl;//5
    std::cout<<first.Pop()<<std::endl;//5
    std::cout<<first.Size()<<std::endl;//0
    std::cout<<first.IsEmpty()<<std::endl;//1

    first.Push(6);
    StackOnList<int> second=std::move(first);
    std::cout<<second.Pop()<<std::endl;//6
    std::cout<<second.Size()<<std::endl;//0
    second.Push(7);

    StackOnList<int> third(second);
    std::cout<<(third==second)<<std::endl;//1
    std::cout<<(third==first)<<std::endl;//0
    int value=third.Pop();

    StackOnList<int> fourth=third;//Assertion failed! Expression: stackOnList.size!=0 && "list is empty"

    //Задание4
    int result=Result("C:\\Clion projects\\practice\\practice_8_StackOnList\\input.txt");
    std::cout<<result;//3
    return 0;
}

int Result(std::string file_name){
    StackOnList<char> Formula;
    std::ifstream fin(file_name);
    if (!fin.is_open()){
        std::cout<<"Error file open";
    }
    int result;
    std::string input;
    std::getline(fin,input);
    std::stringstream input_str(input);
    while(!input_str.eof()){
        char element;
        input_str>>element;

        if(element=='m'){
            input_str>>element;
            Formula.Push(element);
        } else if (isdigit(element)){
            Formula.Push(element);
        }
        else if(element==')'){
            char element_1=Formula.Pop();
            char element_2=Formula.Pop();
            char operation=Formula.Pop();
            if(operation=='a'){
                result=max(atoi(&element_1),atoi(&element_2));
                Formula.Push((char)result);
            }
            else if(operation=='i'){
                result=min(atoi(&element_1),atoi(&element_2));
                Formula.Push((char)result);
            }
        }
    }
    return Formula.Pop();
}
