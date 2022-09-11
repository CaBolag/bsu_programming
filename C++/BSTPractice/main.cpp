
#include "TreeDList.h"
#include "TreeArray.h"

int main() {
  TreeArray<int> tree(6);
  std::cout<<"Enter the amount of elements: ";
  int size,element;
  std::cin>>size;
  for(int i=0;i<size;i++){
    std::cin>>element;
    tree.Insert(element);
  }
  tree.Print();
  std::cout<<"\nEnter the key of searched node:";
  int key;
  std::cin>>key;
  bool search=tree.Search(key);
  return 0;
}
