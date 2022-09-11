
#include "DList.h"
#include "DList.cpp"
int main() {
    DList<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    std::cout<<l<<" ";
    l.push_front(10);
    std::cout<<l<<" ";
    std::cout<<l.pop_back()<<std::endl;
    std::cout<<l.pop_back()<<std::endl;
    std::cout<<l.pop_back()<<std::endl;
    std::cout<<l.pop_back()<<std::endl;

    return 0;
}
