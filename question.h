#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question
{
public:
    Question(const std::string& = "", const std::string& = "", int = 0);
    void askQuestion();
    bool isGuessed() const { return m_guessed; }

private:
    static int getAnswer();
    bool checkAnswer(int);

private:
    std::string m_question;
    std::string m_answer_choice;
    int         m_correct_answer;
    bool        m_guessed;
};

#endif
