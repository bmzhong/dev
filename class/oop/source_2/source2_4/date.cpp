#include "date.h"
#include <iostream>
//判断是否是闰年
bool _Date_::leap_year(int year)
{
    if (year % 4 && !year % 100) //被4整除不被100整除为闰年
        return true;
    if (year % 400) //被400整数位闰年
        return true;
    return false; //其他为平年
}

//传入年份、月份得到当月的天数
int _Date_::get_days(int year, int month)
{
    //月份为1、3、5、7、8、10、12为31天
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    //月份为4、6、9、11为30天
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    //月份为2且是闰年为29天
    if (leap_year(year))
        return 29;
    //月份为2且是平年为28天
    else
        return 28;
}
//输入日期
void _Date_::input(Date &date)
{
    cin >> date.year >> date.month >> date.day;
}
//输出日期
void _Date_::display(const Date &date)
{
    cout << "year: " << date.year << " month: " << date.month << " day: " << date.day << endl;
}
//增加一天后的新日期
void _Date_::add_a_day(Date &date)
{
    //获得当月的总天数
    int days = get_days(date.year, date.month);
    //如果当日的日数值小于当月的总天数，则day加一
    if (date.day < days)
        ++date.day;
    //当日的日数值等于当月的总天数
    else if (date.day == days)
    {
        //如果当月不是12月，则month加一
        if (date.month < 12)
        {
            ++date.month;
            date.day = 1;
        }
        //当月是12月，则进入下一年的第一天
        else if (date.month == 12)
        {
            ++date.year;
            date.month = 1;
            date.day = 1;
        }
    }
}
//增加一个月的新日期
void _Date_::add_a_month(Date &date)
{
    //当月不是12月
    if (date.month < 12)
    {
        //获得下一个月的总天数
        int days = get_days(date.year, date.month + 1);
        //当日的日数值大于下一个月的总天数
        if (days < date.day)
        {
            //日数值等于下个月的总天数
            date.day = days;
            ++date.month; //月份加一
        }
        //当日的日数值小于下一个月的总天数
        else
        {
            //day不变，月份加一
            ++date.month;
        }
    }
    //当月是12月
    else
    {
        //年份加一
        ++date.year;
        //月份变为1
        date.month = 1;
        //获取进入新的一年后的第一个月的总天数
        int days = get_days(date.year, date.month);
        //如果day的数值大于days，则day赋值为days,反之day不变
        if (days < date.day)
        {
            date.day = days;
        }
    }
}
//增加一年后的新日期
void _Date_::add_a_year(Date &date)
{
    //年份加一，月份不变
    ++date.year;
    //获取下一年的month月的总天数
    int days = get_days(date.year, date.month);
    //如果day大于days，则day赋值为days，否则day不变
    if (days < date.day)
    {
        date.day = days;
    }
}
//根据年月日返回星期
int _Date_::get_week(Date date)
{
    /*
    * w ：星期；
    * c ：世纪数 – 1的值，如21世纪，则 = 20；
    * m ：月数，的取值是大于等于3，小于等于14。
    * 某年的1月和2月看作上一年的13月和14月，比如2001年2月1日要当成2000年的14月1日计算；
    * y ：年份，取公元纪念的后两位，如1998年， = 98，2001年， = 1；
    * d ：某月内的日数
    */
    if (date.month <= 2)
    {
        --date.year;
        date.month += 12;
    }
    int m = date.month;
    int d = date.day;
    int y = date.year % 100;
    int c = date.year / 100;
    //蔡勒公式,适用于于1582年10月15日之后的日期
    int w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7;
    //修正w
    if (w < 0)
        w = w + 7;
    return w;
}
//得到下一个星期一的日期
void _Date_::next_Monday(Date &date)
{
    //获取当日的星期。
    int week = get_week(date);
    //如果是星期日则直接增加一天
    if (week == 0)
    {
        add_a_day(date);
    }
    else
    {//其他情况增加8-week天。
        for (int i = 0; i < 8 - week; ++i)
        {
            add_a_day(date);
        }
    }
}