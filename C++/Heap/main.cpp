#include <iostream>
#include "heap.h"
int main() {
    Heap<int> H;
    H.Add(5);
    H.Add(6);
    H.Add(12);
    H.Add(56);
    H.Add(1);
    H.Add(100);
    H.Add(200);
    H.Print();
    return 0;
}
