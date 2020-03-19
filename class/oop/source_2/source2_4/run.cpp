#include <iostream>
#include "date.cpp"
using namespace _Date_;
int main()
{
    Date date = {1700, 1, 1};
    int week = get_week(date);
    system("pause");
    return 0;
}
