//
// Created by Victor on 05.12.2020.
//

#ifndef KR_2_2020__VOCABULARY_H_
#define KR_2_2020__VOCABULARY_H_
#include <iostream>
#include <string>
#include <map>
#include "word_card.h"
#include "bidirectional_list_on_array.h"
#include "file_reader.h"

class Vocabulary {
 public:
  void ReadFileToCards(std::string file_path);
  WordCard* ConvertStringToWordCard(string str);
  void MakeFrequencyVocab();
  void SortWords();
  std::map<string, size_t> CopyToMap();

 private:
  containers::BiDirectionalListOnArray<WordCard *> list_word_cards;

};

WordCard* Vocabulary::ConvertStringToWordCard(std::string str) {
  auto *wordCard = new WordCard(str);
  return wordCard;
}

void Vocabulary::ReadFileToCards(std::string file_path) {
  FileReader reader;
  std::vector<string> words = reader.ReadWords(file_path);
  for (const string &word : words) {
    list_word_cards.PushBack(ConvertStringToWordCard(word));
  }
}

/*void Vocabulary::MakeFrequencyVocab() {
  int size = list_word_cards.Size();
  for (int i = 0; i < size;i++) {
    WordCard** word_1 = list_word_cards[i];
    for (int j = i; j < size; j++) {
      WordCard** word_2 = list_word_cards[j];
      if (*word_1 == *word_2) {
        delete word_2;
        word_1.IncCounter();
        list_word_cards.Erase(j);
      }
    }
  }
}


void Vocabulary::SortWords() {
  int n = list_word_cards.Size();
  for (int i = 0; i < n; ++i) {
    auto ref = list_word_cards[i];
    auto cmp = list_word_cards[i + 1];
    if (*cmp < *ref) {
      auto temp = ref;
      list_word_cards[i] = cmp;
      list_word_cards[i + 1] = ref;
    }
  }
}

std::map<std::string, size_t> Vocabulary::CopyToMap() {
  int size = list_word_cards.Size();
  std::map<std::string, size_t> result;
  for (int i = 0; i < size; i++) {
    result[list_word_cards[i].GetWord] = list_word_cards[i].GetCounter();
  }
  return result;
}*/


#endif //KR_2_2020__VOCABULARY_H_
