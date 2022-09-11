//#include <iostream>  
//int main() {
//	{//task1
//		std::cout << "Enter amount of seconds: " << std::endl;
//		int amount, hour, min, sec;
//		std::cin >> amount;
//		_asm {
//			mov eax, amount
//			mov ecx, 3600
//			cdq
//			div ecx
//			mov hour, eax
//
//			mov eax, edx
//			mov ecx, 60
//			cdq
//			div ecx
//			mov min, eax
//			mov sec, edx
//		}
//		std::cout << hour << min << sec << "\n";
//	}
//
//	{
//		//task2
//		int a, b, c, result=0;
//		std::cin >> a >> b >> c;
//		_asm {
//			mov eax, a
//			mov ecx,2
//			cdq
//			div ecx
//			cmp edx, 0
//			je divided1
//			divided1:
//			mov eax, a
//				add result, eax
//
//				mov eax, b
//				mov ecx,2
//				cdq
//				div ecx
//				cmp edx, 0
//				je divided2
//				divided2 :
//			mov eax, b
//				add result, eax
//
//				mov eax, c
//				mov ecx,2
//				cdq
//				div ecx
//				cmp edx, 0
//				je divided3
//				divided3 :
//			mov eax, c
//				add result, eax
//			
//		}
//		std::cout << result << "\n";
//	}
//
//    return 0;
//}
//#include <iostream>  
////6.	Пользователь вводит номер года. Необходимо написать программу, которая выведет количество дней в этом году
//
//int main() {
//    int year, days;
//    std::cout << "Enter year\n";
//    std::cin >> year;
//    _asm {
//        mov eax, year
//        mov ebx, 400
//        cdq
//        div ebx
//        cmp edx, 0
//        jz next
//        jnz next2
//        next :
//        mov days, 366
//            jmp the_end
//            next2 :
//        mov eax, year
//            mov ebx, 4
//            cdq
//            div ebx
//            cmp edx, 0
//            jz next3
//            jnz next5
//            next3 :
//        mov eax, year
//            mov ebx, 100
//            cdq
//            div ebx
//            cmp edx, 0
//            jnz next4
//            jz next5
//            next4 :
//        mov days, 366
//            jmp the_end
//            next5 :
//        mov days, 365
//            jmp the_end
//            the_end :
//    }
//
//	{
//		//task3
//		int year, amount;
//		std::cin >> year;
//		_asm {
//			mov eax, year
//			div 100
//			cmp eax, 0
//			je divided_100
//			jne not_divided_100
//			divided_100 :
//			jmp divided_4_
//				not_divided_100 :
//			jmp divided_400_
//				divided_400_ :
//			mov eax, year
//				div 400
//				cmp eax, 0
//				je not_leap
//				jne divided_4_
//				divided_4_ :
//			mov eax, year
//				div 4
//				cmp eax, 0
//				je leap
//				jne not_leap
//				leap :
//			mov amount, 366
//				not_leap :
//				mov amount, 365
//		}
//		std::cout >> amount;
//
//	}
//    return 0;
//}


#include <iostream>
#include <stdlib.h>
#include <search.h>
#include <string.h>
int compare_int(const void* a, const void* b) {
    return *(int*)a-*(int*)b;
}

int compare_double(const void* a, const void* b) {

    if (*(double*)a - *(double*)b < 0) {
        return -1;
       }
    if (*(double*)a - *(double*)b > 0) {
        return 1;
    }
    if (*(double*)a - *(double*)b == 0) {
        return 0;
    }
}

//int compare_struct(const void* a, const void* b);

int main() {
    int array1[] = { 4,6,3,2 };
    qsort(array1, sizeof(array1) / sizeof(int), sizeof(array1), compare_int);

    double array2[] = { 1.2,3.4,0.1,5.2 };
    qsort(array1, sizeof(array2) / sizeof(double), sizeof(array2), compare_double);


    struct MyStruct {
        int x;
        int y;

    };


    return 0;
}

int compare_struct(const void *a, const void *b){
  return *((*MyStruct)a.x)- *(*MyStruct)b.x
}