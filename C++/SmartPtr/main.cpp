#include <iostream>
#include <memory>

int main() {
  int i=5;
  std::shared_ptr<MyClass> c(new MyClass(i),del_MyClass);

  return 0;
}
