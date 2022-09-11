#include <string>
class Model {
public:
	void SetStrings(std::vector<std::string>strings) { strings_ = strings; };
	void UpdateSymbolsWordsFrequance(int number) {
		std::map<std::string, int> words_frequance_;
		std::map<char, int> symbols_frequance_;
		std::string str = strings_[number - 1];
			std::stringstream in_str(str);
			std::string word;
			while (getline(in_str, word, ' ')) {
				words_frequance_[word]++;
				for (int i = 0; i < word.size(); i++) {
					char symbol = word[i];
					symbols_frequance_[symbol]++;
				}
			}
	};

	std::map<char, int> GetSymbolsFrequance()const { return symbols_frequance_; };
	std::map<std::string, int> GetWordsFrequance() const{ return words_frequance_; };

private:
	 std::vector<std::string> strings_;
	 /*std::map<char, int> symbols_frequance_;
	 std::map<std::string, int> words_frequance_;*/

};
