//
// Created by Victor on 14.01.2021.
//

#include "shop.h"
namespace exam{
std::shared_ptr<Book> Shop::CreateBook(long long isbn) {
  exam::Book new_book(isbn,"",0);
  std::shared_ptr<Book> ptr=std::make_shared<Book>(new_book);
  books_[isbn]=ptr;
  authors_= nullptr;
  count_authors_=0;
}
std::shared_ptr<Book> Shop::CreateBook(long long isbn, string title, double price) {
  exam::Book new_book(isbn,title,price);
  std::shared_ptr<Book> ptr=std::make_shared<Book>(new_book);
  books_[isbn]=ptr;
  authors_= nullptr;
  count_authors_=0;
}
std::shared_ptr<Book> Shop::CreateBook(long long isbn, string title, double price, vector<std::shared_ptr<Author>> authors,
                                       const char *publisher, int year, int pages) {
    exam::Book new_book(isbn,title,authors, publisher, year, pages, price);
    std::shared_ptr<Book> ptr=std::make_shared<Book>(new_book);
    books_[isbn]=ptr;
    std::shared_ptr<Author>* ptr_authors=authors_;
    count_authors_=authors.size();
}
bool Shop::AddBook(std::shared_ptr<Book> book) {
 /* if(books_.find(book->isbn()== nullptr)){
    return false;
  }
  if(book== nullptr){
    throw std::invalid_argument("Error!");
  }
  books_.insert(std::make_pair(book->isbn(),book));
  count_authors_++;*/
}
}

