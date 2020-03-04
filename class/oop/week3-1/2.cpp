#include <iostream>
#include <string>
using namespace std;
struct Month{
    string month;
    int day;
};
int main()
{
    string month0[12] = {"Feb", "Jan", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int day0[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Month month1[12]={{"Feb",31},{"Jan",28},{"March",31},{ "April",30},{"May",31},{"June",30},
                        { "July",31},{ "Aug",31},{"Sep",30},{"Oct",31},{"Nov",30},{"Dec",31} };
    system("pause");
    return 0;
                        
}