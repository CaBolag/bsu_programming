//
// Created by Victor on 14.01.2021.
//

#ifndef EXAM_SEM_1__BOOK_H_
#define EXAM_SEM_1__BOOK_H_
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <string.h>
#include "author.h"
using std::string;
using std::vector;
namespace exam {
class Book {
 private:
  long long int isbn_;
  string title_;
  vector<std::shared_ptr<Author>> authors_;
  const char* publisher_;
  int year_;
  int pages_;
  double price_;

 public:
  Book(long long int isbn=0);
  Book(long long int isbn,string title,double price);
  Book(long long int isbn=0,string title="", vector<std::shared_ptr<Author>> authors={nullptr}, const char* publisher= "", int year=0, int pages=0,int price=0);
  ~Book()=default;
  long long int isbn() const {return isbn_;}
  string title() const {return title_;}
  vector<std::shared_ptr<Author>> authors() const{return authors_;}
  const char* publisher() const {return publisher_;}
  int year() const {return year_;}
  int pages() const {return pages_;}
  double price() const {return price_;}

  Book(Book &other);
  Book(Book &&other);
  Book &operator=(const Book &other);
  Book &operator=(Book &&other);
  friend std::ostream& operator<< (std::ostream &out, const Book &book);
  bool operator <(const Book &other);
};
}
#endif //EXAM_SEM_1__BOOK_H_
