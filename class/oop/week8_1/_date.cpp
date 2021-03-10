#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "_date.h"
using namespace std;

Date Date::default_date = {1970, 1, 1};

Date::Date(int yy = default_date.year, int mm = default_date.month, int dd = default_date.day) throw(Bad_date)
{

    if (!right_date(yy, mm, dd))
        throw Bad_date("初始化日期不是一个合法的日期");
    year = yy;
    month = mm;
    day = dd;
}

int Date::get_day() const
{
    return day;
}
int Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

string Date::string_rep() const
{
    stringstream ss;
    string yy, mm, dd;
    ss << year;
    ss >> yy;
    ss.clear();
    ss << month;
    ss >> mm;
    ss.clear();
    ss << day;
    ss >> dd;
    ss.clear();
    return yy + "." + mm + "." + dd;
}

void Date::char_rep(char s[]) const throw(out_of_range)
{
    string date = Date::string_rep();
    int len = date.size();
    int len1 = sizeof(s) / sizeof(char);
    if (len >= len1)
        throw out_of_range("s空间不够，下标会越界");//系统不检查下标越界，自己抛出
    for (int i = 0; i < len; ++i)
    {
        s[i] = date[i];
    }
}


void Date::set_default(int yy, int mm, int dd) throw(Bad_date)
{
    if (!right_date(yy, mm, dd))
        throw Date::Bad_date("设置的默认日期不对");
    default_date.year = yy;
    default_date.month = mm;
    default_date.day = dd;
}

Date &Date::add_year(int n)
{
    for (int i = 0; i < n; ++i)
    {
        add_a_year(*this);
    }
    return *this;
}

Date &Date::add_month(int n)
{
    for (int i = 0; i < n; ++i)
    {
        add_a_month(*this);
    }
    return *this;
}

Date &Date::add_day(int n)
{
    for (int i = 0; i < n; ++i)
    {
        add_a_month(*this);
    }
    return *this;
}
bool Date::leap_year(int yy)
{
    if (!(yy % 4) && yy % 100) //被4整除不被100整除为闰年
        return true;
    if (!(yy % 400)) //被400整数位闰年
        return true;
    return false; //其他为平年
}

int Date::get_days(int yy, int mm)
{
    //月份为1、3、5、7、8、10、12返回31天
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        return 31;
    //月份为4、6、9、11返回30天
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return 30;
    //月份为2且是闰年返回29天
    if (leap_year(yy))
        return 29;
    //月份为2且是平年返回28天
    else
        return 28;
}

bool Date::right_date(const int &yy, const int &mm, const int &dd)
{
    if (yy < 0 || mm < 0 || mm > 12)
        return false;
    if (dd < 0 || dd > get_days(yy, mm))
        return false;
    return true;
}

void Date::add_a_year(Date &date)
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
//增加一个月的新日期
void Date::add_a_month(Date &date)
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
        //date.day不变，因为1月和12月总天数一样多
    }
}

void Date::add_a_day(Date &date)
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
