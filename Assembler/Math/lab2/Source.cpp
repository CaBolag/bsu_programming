#include <iostream>
//task1
//task2
int main() {
    {
        int result = 0, n;
        std::cout << "Enter the number:";
        std::cin >> n;
        //task1
        _asm {
            mov eax, n
            mov ecx, 0
            again:
            cmp eax, 1
                jz end
                test eax, 1
                jz yes
                inc ecx
                shr eax, 1
                jmp again
                yes :
            shr eax, 1
                jmp again
                end :
            inc ecx
                mov result, ecx
        }
        if (result == 1) {
            std::cout << "Yes,is a power of two";
        }
        else { std::cout << "No,is not a power of two"; }
    }
    {
        int result = 0, n;
        std::cout << "\nEnter the number:";
        std::cin >> n;
        //task2
        _asm {
            mov eax, n
            mov ecx, 0
            _again:
            test eax, 1
                jz _yes
                inc ecx
                shr eax, 1
                cmp eax, 1
                jz _end
                jmp _again
                _yes :
            shr eax, 1
                cmp eax, 1
                jz _end
                jmp _again
                _end :
            inc ecx
                mov result, ecx
        }
      std::cout << "Amount:" << result;
   }
    {
        //task3
        int a,n=1;
        std::cout << "\nEnter the number:";
        std::cin >> a;
        _asm {
            _next:
            mov eax, a
            mov ecx, n
            imul ecx
            jo end_
            inc n
                jmp _next
                end_:
        }
        std::cout << "N=" << n;
    }
}
