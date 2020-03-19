/*
 * 文件描述：
 *		   测试Date类型的相关操作。
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/19
 *
 */
#include <iostream>
#include "date.cpp"
#include <vector>
using namespace _Date_;
int main()
{
    Date date;

    cout << "input date: " << endl;
    //输入日期
    input(date);
    //将这个日期复制5份，分别测试5中操作。
    vector<Date> v(5, date);

    cout << "new date after adding a day: " << endl;
    add_a_day(v[0]);
    display(v[0]);

    cout << "new date after adding a month: " << endl;
    add_a_month(v[1]);
    display(v[1]);

    cout << "new date after adding a year:  " << endl;
    add_a_year(v[2]);
    display(v[2]);

    cout << "return week by date:  " << endl;
    int week = get_week(v[3]);
    cout << "    "<<weekday[week] << endl;

    cout << "new date next Monday: " << endl;
    next_Monday(v[4]);
    display(v[4]);

    system("pause");
    return 0;
}
