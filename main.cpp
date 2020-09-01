#include "questionlist.h"
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    QuestionList list;
    list.startTest();
    list.printResultTest();
    return 0;
}
