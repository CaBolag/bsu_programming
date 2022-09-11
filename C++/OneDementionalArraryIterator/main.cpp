
#include "ArrayReverseIterator.h"

int main() {

  Array<char> arr;
  arr.Add('c');
  arr.Add('d');
  arr.InsertAt('a',0);
  arr.InsertAt('b',1);


  Array<char>::ArrayIterator iterator(&arr);
  arr.PrintAll(iterator);
  std::cout<<std::endl;
  ArrayReverseIterator<char> reverse_iterator(&arr);
  for(reverse_iterator.First(); !reverse_iterator.IsDone(); reverse_iterator.Next()) {
    std::cout<<reverse_iterator.CurrentItem();
  }

  return 0;
}

