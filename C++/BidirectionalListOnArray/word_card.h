
#ifndef KR_2_2020__WORDCARD_H_
#define KR_2_2020__WORDCARD_H_
#include <iostream>

using std::string;
class WordCard {
 public:
  WordCard()=default;
  WordCard(const string & );

  WordCard(const WordCard&);
  WordCard operator=(const WordCard &other);

  WordCard(WordCard &&);
  WordCard &operator=(WordCard &&other);

  ~WordCard()=default;

  string GetWord(){return word_; };
  size_t GetCounter(){return counter_; };

  void IncCounter();

  bool operator==(const WordCard &other);
  bool operator!=(const WordCard &other);

  friend bool operator<(const WordCard &first,const WordCard &second);

 private:
  string word_;
  size_t counter_;
};

WordCard::WordCard(const string &str) {
  word_=str;
  counter_=1;
}

WordCard::WordCard(const WordCard &word_card) {
  word_=word_card.word_;
  counter_=word_card.counter_;
}

WordCard::WordCard(WordCard && word_card):word_(word_card.word_),counter_(word_card.counter_) {
  word_card.word_= nullptr;
  word_card.counter_=0;
}

WordCard WordCard::operator=(const WordCard &other) {
  if (this != &other) {
    word_ = other.word_;
    counter_ = other.counter_;
  }
  return *this;
}

WordCard &WordCard::operator=(WordCard &&other) {
  if (this != &other) {
    word_= "";
    word_ = other.word_;
    counter_ = other.counter_;
  }
  other.word_= nullptr;
  other.counter_=0;
  return *this;
}

void WordCard::IncCounter() {
  counter_+=1;
}

bool WordCard::operator==(const WordCard &other) {
  return (word_==other.word_);
}

bool WordCard::operator!=(const WordCard &other) {
  return (word_!=other.word_);
}

bool operator<(WordCard &first, WordCard &second) {
  return (first.GetCounter() < second.GetCounter());
}

#endif //KR_2_2020__WORDCARD_H_
