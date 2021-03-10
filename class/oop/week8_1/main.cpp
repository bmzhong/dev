#include <iostream>
#include <stdexcept>
#include <string>
#include "_date.cpp"
//#include "_date.h"
using namespace std;

int main()
{
    try
    {
        Date d1;

        cout << d1.get_year() << "-" << d1.get_month() << "-" << d1.get_day() << endl;

		d1.add_day(5);
        d1.add_month(4);
        d1.add_year(3);

		cout<<"加3年4月5天后的日期："<< d1.get_year() << "-" << d1.get_month() << "-" << d1.get_day() << endl;
		
        Date d2(2020, 4, 10);
        
        cout << d2.string_rep() << endl;

        Date::set_default(2019, 4, 12);

        char s[3];
    //  d2.char_rep(s);//抛出out_of_range异常

        Date d3(2020,-2,222);//抛出异常
   
    }
    catch (Date::Bad_date &e1)
    {
        cerr << e1.get_msg() << endl;
    }
    catch (out_of_range &e2)
    {
        cerr << e2.what() << endl;
    }
    cout<<"jifdasfd"
    "fdasfdasf"<<endl;
    system("pause");
    return 0;
}
