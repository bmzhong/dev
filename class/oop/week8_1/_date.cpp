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
        throw Bad_date("��ʼ�����ڲ���һ���Ϸ�������");
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
        throw out_of_range("s�ռ䲻�����±��Խ��");//ϵͳ������±�Խ�磬�Լ��׳�
    for (int i = 0; i < len; ++i)
    {
        s[i] = date[i];
    }
}


void Date::set_default(int yy, int mm, int dd) throw(Bad_date)
{
    if (!right_date(yy, mm, dd))
        throw Date::Bad_date("���õ�Ĭ�����ڲ���");
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
    if (!(yy % 4) && yy % 100) //��4��������100����Ϊ����
        return true;
    if (!(yy % 400)) //��400����λ����
        return true;
    return false; //����Ϊƽ��
}

int Date::get_days(int yy, int mm)
{
    //�·�Ϊ1��3��5��7��8��10��12����31��
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        return 31;
    //�·�Ϊ4��6��9��11����30��
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return 30;
    //�·�Ϊ2�������귵��29��
    if (leap_year(yy))
        return 29;
    //�·�Ϊ2����ƽ�귵��28��
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
    //��ݼ�һ���·ݲ���
    ++date.year;
    //��ȡ��һ���month�µ�������
    int days = get_days(date.year, date.month);
    //���day����days����day��ֵΪdays������day����
    if (days < date.day)
    {
        date.day = days;
    }
}
//����һ���µ�������
void Date::add_a_month(Date &date)
{
    //���²���12��
    if (date.month < 12)
    {
        //�����һ���µ�������
        int days = get_days(date.year, date.month + 1);
        //���յ�����ֵ������һ���µ�������
        if (days < date.day)
        {
            //����ֵ�����¸��µ�������
            date.day = days;
            ++date.month; //�·ݼ�һ
        }
        //���յ�����ֵС����һ���µ�������
        else
        {
            //day���䣬�·ݼ�һ
            ++date.month;
        }
    }
    //������12��
    else
    {
        //��ݼ�һ
        ++date.year;
        //�·ݱ�Ϊ1
        date.month = 1;
        //date.day���䣬��Ϊ1�º�12��������һ����
    }
}

void Date::add_a_day(Date &date)
{
    //��õ��µ�������
    int days = get_days(date.year, date.month);
    //������յ�����ֵС�ڵ��µ�����������day��һ
    if (date.day < days)
        ++date.day;
    //���յ�����ֵ���ڵ��µ�������
    else if (date.day == days)
    {
        //������²���12�£���month��һ
        if (date.month < 12)
        {
            ++date.month;
            date.day = 1;
        }
        //������12�£��������һ��ĵ�һ��
        else if (date.month == 12)
        {
            ++date.year;
            date.month = 1;
            date.day = 1;
        }
    }
}
