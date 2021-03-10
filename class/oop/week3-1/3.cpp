#include <iostream>
#include <string>
using namespace std;
struct Date
{
    int year, month, day;

    Date(int _year, int _month, int _day)
    {
        year = _year;
        month = _month;
        day = _day;
    }
};

void input(Date &date)
{
    cin >> date.year >> date.month >> date.day;
}

void output(const Date date)
{
    cout << date.year << " " << date.month << " " << date.day<<endl;
}

int main()
{
    Date date(2020, 3, 2);
    input(date);
    output(date);
    system("pause");
    return 0;
}