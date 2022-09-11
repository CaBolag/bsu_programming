#pragma once
#include <iostream>
#include <vector>
class Answer {
public:
	Answer() { answers_.push_back(0); };
	Answer(std::vector<int> answer) :answers_(answer) {}
	~Answer() = default;
	void ChangeAnswer(std::vector<int> new_) { answers_ = new_; }
	std::vector<int> GetAnswers() { return answers_; }

private:
	std::vector<int> answers_;
};
