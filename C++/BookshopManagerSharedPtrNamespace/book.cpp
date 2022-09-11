//
// Created by Victor on 14.01.2021.
//

#include "book.h"
namespace exam {
Book::Book(long long isbn) : isbn_(isbn) {
  int count;
  while (isbn) {
    isbn /= 10;
    count++;
  }
  if (isbn < 0 || count != 13) {
    throw std::invalid_argument("Error! Unvailable isbn.");
  }
  year_ = 0;
  pages_ = 0;
  price_ = 0;
  publisher_ = nullptr;
  authors_ = {nullptr};
}
Book::Book(long long int isbn, std::string title, double price) : Book(isbn) {
  if (price < 0) {
    throw std::invalid_argument("Error! Price is negstive.");
  }
  if (title.empty()) {
    throw std::invalid_argument("Error! Unvailable title.");
  }
  title_ = title;
  price_ = price;
}
Book::Book(long long int isbn,
           string title,
           vector<std::shared_ptr<Author>> authors,
           const char *publisher,
           int year,
           int pages,
           int price) :
    Book(isbn, title, price) {

  if (publisher == nullptr || year < 0 && pages < 0) {
    throw std::invalid_argument("Error!");
  }
  for (int i = 0; i < authors.size(); ++i) {
    authors_[i] = authors[i];
  }
  publisher_ = publisher;
  year_ = year;
  pages_ = pages;
}

Book::Book(Book &other) :isbn_(other.isbn_),title_(other.title_),publisher_(other.publisher_),year_(other.year_),pages_(other.pages_),price_(other.price_){
  for(auto elem:other.authors_){
    authors_.push_back(elem);
  }
  int size=strlen(other.publisher_);
  for(int i=0;i<size;++i){
    publisher_[i]=other.publisher_[i];
  }
}

Book::Book(Book &&other):isbn_(other.isbn_),title_(other.title_),publisher_(other.publisher_){
    for(auto elem:other.authors_){
      authors_.push_back(elem);
    }
    int size=strlen(other.publisher_);
    for(int i=0;i<size;++i){
      publisher_[i]=other.publisher_[i];
    }
    other.isbn_=0;
    other.title_="";
    other.publisher_="";
    other.year_=0;
    other.pages_=0;
    other.price_=0;
}

Book & Book::operator=(const Book &other) {
  if(&other!=this){
    isbn_=other.isbn_;
    title_=other.title_;
    authors_.clear();
    for(auto elem:other.authors_){
      authors_.push_back(elem);
    }
    int size=strlen(other.publisher_);
    publisher_=new char[size];
    for(int i=0;i<size;++i){
      publisher_[i]=other.publisher_[i];
    }
    year_=other.year_;
    pages_=other.pages_;
    price_=other.price_;
  }
  return *this;
}

Book & Book::operator=( Book &&other) {
  authors_.clear();
  for(auto elem:other.authors_){
    authors_.push_back(elem);
  }
  int size=strlen(other.publisher_);
  publisher_=new char[size];
  for(int i=0;i<size;++i){
    publisher_[i]=other.publisher_[i];
  }
  other.isbn_=0;
  other.title_="";
  other.publisher_="";
  other.year_=0;
  other.pages_=0;
  other.price_=0;
}

bool Book::operator<(const Book &other) {

  if (this->price_ < other.price_) {
    return true;
  } else
    return false;
}

std::ostream &operator<<(std::ostream &out, const Book &book) {
  std::string authors;
  for (auto &autor : book.authors()) {
    std::string birth_year = std::to_string(autor->birth_year());
    authors = autor->full_name() + ", " + birth_year;
  }
  out << "Book(ISBN: " << book.isbn() << ", title: " << book.title()
      << " author(s): { " << authors << " }, publisher: " << *book.publisher() << ", year: " << book.year()
      << ", pages: " << book.pages() << ")";
  return out;
}
}
