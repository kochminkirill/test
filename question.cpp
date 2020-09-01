#include "question.h"
#include <iostream>
#include "windows.h"

Question::Question(const std::string &question, const std::string &answer_choice, int correct_answer)
    : m_question{ question }, m_answer_choice{ answer_choice }, m_correct_answer{ correct_answer } {}

void Question::askQuestion()
{
    std::cout << m_question << "\n";
    std::cout << m_answer_choice << '\n';
    int answer = getAnswer();
    if(checkAnswer(answer))
    {
        m_guessed = true;
        std::cout << "It's correct!\n";
    }
    else
    {
        m_guessed = false;
        std::cout << "It isn't correct! The correct answer:" << m_correct_answer << '\n';
    }
    Sleep(5000);
}

//support functions
int Question::getAnswer()
{
    std::cout << "Choose answer:";
    int answer;
    std::cin >> answer;
    return answer;
}

bool Question::checkAnswer(int answer)
{
    return (answer == m_correct_answer) ? true : false;
}
