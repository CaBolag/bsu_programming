#include <iostream>
#include "queue_linked_list.h"
int main() {
    QueueLinkedList<int>Q;
    Q.Push(5);
    QueueLinkedList<int>q(Q);
    std::cout<<q.PopBack();
    return 0;
}
