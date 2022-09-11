#pragma once
#include <fstream>
#include <sstream>
#include <algorithm>
#include"Question.h"
#include"Answer.h"


class TestProgram {
public:
    TestProgram() = default;
    ~TestProgram() = default;
    void UploadQuestions(std::string file_name) {
        std::ifstream in_file(file_name);
        if (!in_file.is_open()) {
            std::cout << "Error file open\n";
            return;
        };
        while (!in_file.eof()) {
            std::string question_str;
            std::getline(in_file, question_str,'\n');
            std::stringstream in(question_str);
            int question_id=1;
            std::string question_text;
            std::getline(in, question_text, ';');
            std::string questions;
            std::getline(in,questions,';');
            std::stringstream qs(questions);
            std::vector<std::string> answer_options;
            std::string answer_option;
            while (std::getline(qs, answer_option, ',')) {
                answer_options.push_back(answer_option);
            }
            int correct_answer;
            std::vector<int> correct_answers;
            while (!in.eof()) {
                in >> correct_answer;
                correct_answers.push_back(correct_answer);
            }

            if (correct_answers.size() == 1) {
                Question question (question_id, "radio", question_text, answer_options, correct_answers);
                questions_.push_back(question);
                Answer answer;
                answers_.push_back(answer);
            }
            else {
                Question question(question_id, "check", question_text, answer_options, correct_answers);
                questions_.push_back(question);
                Answer answer;
                answers_.push_back(answer);
            }
            question_id++;
            
            
        }
    }

    void ChangeAnswer(int question_id, std::vector<int> new_answer) {
        answers_[question_id - 1].ChangeAnswer(new_answer);
    }

    std::vector <bool> GetResult() {
        std::vector<bool> result; //элемент, имеющий индекс i, отражает првильность ответа на вопрос i
        for (int i = 0; i < questions_.size(); ++i) {
            Question question = questions_[i];
            if (question.GetCorrectAnswers() == answers_[i].GetAnswers()) {
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }
        return result; 
    };

    std::vector<Question> GetQuestions()const { return questions_; }
    std::vector<Answer> GetAnswers()const { return answers_; }


private:
	std::vector<Question> questions_;//индекс Question в векторе соответствует номеру вопроса
	std::vector<Answer> answers_;// индекс Answer в векторе соответсвует номеру вопроса, которому принадлежит данный ответ

};