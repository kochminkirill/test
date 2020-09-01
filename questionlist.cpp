#include "questionlist.h"
#include "constants.h"
#include <iostream>

QuestionList::QuestionList()
{
    m_list = new Question[Constants::max_question];

    m_list[0] = Question{ "\"What is a chicken?\"\n",  "Answer choice:\n"
                                                       "1. fish\n"
                                                       "2. bird\n"
                                                       "3. animal\n", 2};

    m_list[1] = Question{ "\"What is a cat?\"\n",      "Answer choice:\n"
                                                       "1. animal\n"
                                                       "2. fish\n"
                                                       "3. insect\n", 1};

    m_list[2] = Question{ "\"What is a beatle?\"\n",   "Answer choice:\n"
                                                       "1. fish\n"
                                                       "2. bird\n"
                                                       "3. insect\n", 3};

    m_list[3] = Question{"\"What is a butterfly?\"\n", "Answer choice:\n"
                                                       "1. bird\n"
                                                       "2. fish\n"
                                                       "3. insect\n", 3};

    m_list[4] = Question{"\"What is a dog?\"\n",       "Answer choice:\n"
                                                       "1. bird\n"
                                                       "2. animal\n"
                                                       "3. fish\n",   2};
}

void QuestionList::startTest() const
{
    int random_question{ 0 };
    std::vector<int> already_ask_questions;

    for(int question{ 0 }; question < Constants::max_question; ++question)
    {
        random_question = getRandomNumber(0, Constants::max_question - 1);
        if(!isAlreadyAsk(already_ask_questions, random_question))
        {
            std::cout << "Question #" << question + 1 << ": ";
            m_list[random_question].askQuestion();
            already_ask_questions.push_back(random_question);
            system("cls");
        }
        else
            --question;
    }
}

void QuestionList::printResultTest() const
{
    int result{ 0 };
    for(int question{ 0 }; question < Constants::max_question; ++question)
        if(m_list[question].isGuessed())
            ++result;

    switch (result)
    {
        case 1:
        case 2: std::cout << "Your Score: 2.\n"; break;
        case 3: std::cout << "Your score: 3.\n"; break;
        case 4: std::cout << "Your score: 4.\n"; break;
        case 5: std::cout << "Your score: 5.\n"; break;
    }
}

int QuestionList::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 /(static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool QuestionList::isAlreadyAsk(const std::vector<int> &v, int question)
{
    for(const auto &elem : v)
        if(elem == question)
            return true;

    return false;
}











