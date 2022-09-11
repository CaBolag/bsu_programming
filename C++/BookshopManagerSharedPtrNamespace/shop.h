//
// Created by Victor on 14.01.2021.
//

#ifndef EXAM_SEM_1__SHOP_H_
#define EXAM_SEM_1__SHOP_H_
#include <map>
#include "book.h"
namespace exam {
class Shop {
 private:
  std::map<long long int, std::shared_ptr<Book>> books_;
  int count_authors_;
  std::shared_ptr<Author>* authors_;
 public:
  Shop()=default;
  ~Shop()=default;
  std::shared_ptr<Book> CreateBook(long long int isbn);
  std::shared_ptr<Book> CreateBook(long long int isbn,string title, double price);
  std::shared_ptr<Book> CreateBook(long long int isbn,string title, double price, vector<std::shared_ptr<Author>> authors,
                                   const char* publisher, int year, int pages);
  bool AddBook(std::shared_ptr<Book> book);
  vector<std::shared_ptr<Book>> FindByTitle(string title){
    vector<std::shared_ptr<Book>> books_by_title;
    for(auto& item : books_){
      if(item.second->title()==title){
        books_by_title.push_back(item.second);
      }
    }
    return books_by_title;
  }
  vector<std::shared_ptr<Book>> FindByPublisher(string publisher){
    vector<std::shared_ptr<Book>> books_by_publisher;
    for(auto& item : books_){
      if(item.second->publisher()==publisher){
        books_by_publisher.push_back(item.second);
      }
    }
    return books_by_publisher;
  }

  vector<std::shared_ptr<Book>> AllBooks(){
    vector<std::shared_ptr<Book>> all_books;
    for(auto& item : books_) {
      all_books.push_back(item.second);
    }
    return all_books;
  }
  bool DeleteBook(std::shared_ptr<Book> delete_book){
    for(auto& item : books_){
      if(item.second=delete_book){
        books_.erase(item.first);
      }
    }
  }
  std::shared_ptr<Author> CreateAuthor(string last_name,string first_name,string second_name,short birth_year){
    Author new_author(last_name, first_name, second_name, birth_year);
    auto ptr=std::make_shared<Author>(new_author);
    return ptr;
  }
  bool AddAuthor(std::shared_ptr<Author>){
  }
  vector<std::shared_ptr<Author>> FindBySubstringInFullName(string substring){};
};
}
#endif //EXAM_SEM_1__SHOP_H_
