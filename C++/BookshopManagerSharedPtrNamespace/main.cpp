#include <iostream>
#include "shop.h"
#include "book.h"
using namespace std;
int main() {
  exam::Book book_1(1234567891011,"Programming","Straustrup","Wialms",1950,840,100);
  exam::Book book_2=book_1;
  exam::Book book_3(std::move(book1));
  cout<<book_1.isbn();
  for(auto elem:book_1.authors()){
    cout<<elem->full_name();
  }
  cout<<book_2.isbn();
  for(auto elem:book_1.authors()){
    cout<<elem->full_name();
  }
  cout<<book_3.isbn();
  cout<<book_1.operator<(book_2);
  exam::Book book_4(12323);  //error
  return 0;
}
