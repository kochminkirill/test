#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include "question.h"
#include <vector>

class QuestionList
{
public:
   QuestionList();
   ~QuestionList() { delete [] m_list; }

   void startTest() const;
   void printResultTest() const;

private:
   static int getRandomNumber(int, int);
   static bool isAlreadyAsk(const std::vector<int>&, int);

private:
    Question *m_list;
};

#endif
