#pragma once
#include<iostream>
#include<vector>
class Question {
public:
	Question() = default;
	Question(int id, std::string type, std::string question_text, std::vector<std::string> answer_options, std::vector<int> correct_answers)
		: type_(type), answer_options_(answer_options), question_text_(question_text), correct_answers_(correct_answers) { }
	~Question() = default;
	Question& operator=(const Question& q) {
		type_ = q.type_;
		question_text_ = q.question_text_;
		for (int i = 0; i < answer_options_.size(); i++) {
			answer_options_[i] = q.answer_options_[i];
		}

		for (int i = 0; i < correct_answers_.size(); i++) {
			correct_answers_[i] = q.correct_answers_[i];
		}

		return *this;
	}
	std::string GetQuestionText() const { return question_text_; }
	std::vector<int> GetCorrectAnswers()const { return correct_answers_; }
	std::string GetType()const { return type_; }
	std::vector<std::string> GetAnswersOptions()const { return answer_options_; }

private:
	std::string type_;
	std::string question_text_;
	std::vector<std::string> answer_options_;
	std::vector<int> correct_answers_;
};