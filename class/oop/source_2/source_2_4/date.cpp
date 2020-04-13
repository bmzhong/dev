/*
 * �ļ�������
 *		   ʵ��Date���͵���غ����ӿ�
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/03/19
 *
 */
#include "date.h"
#include <iostream>
//�ж��Ƿ�������
bool _Date_::leap_year(int year)
{
    if (! (year % 4) && year % 100) //��4��������100����Ϊ����
        return true;
    if (! (year % 400)) //��400����λ����
        return true;
    return false; //����Ϊƽ��
}

//������ݡ��·ݵõ����µ�����
int _Date_::get_days(int year, int month)
{
    //�·�Ϊ1��3��5��7��8��10��12����31��
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    //�·�Ϊ4��6��9��11����30��
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    //�·�Ϊ2�������귵��29��
    if (leap_year(year))
        return 29;
    //�·�Ϊ2����ƽ�귵��28��
    else
        return 28;
}
//��������
void _Date_::input(Date &date)
{
    cin >> date.year >> date.month >> date.day;
}
//�������
void _Date_::display(const Date &date)
{
    cout << "    " <<date.year << "/" << date.month << "/" << date.day << endl;
}
//����һ����������
void _Date_::add_a_day(Date &date)
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
//����һ���µ�������
void _Date_::add_a_month(Date &date)
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
//����һ����������
void _Date_::add_a_year(Date &date)
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
//���������շ�������
int _Date_::get_week(Date date)
{
    /*
    * w �����ڣ�
    * c �������� �C 1��ֵ����21���ͣ��� = 20��
    * m ����������ȡֵ�Ǵ��ڵ���3��С�ڵ���14��
    * ĳ���1�º�2�¿�����һ���13�º�14�£�����2001��2��1��Ҫ����2000���14��1�ռ��㣻
    * y ����ݣ�ȡ��Ԫ����ĺ���λ����1998�꣬ = 98��2001�꣬ = 1��
    * d ��ĳ���ڵ�����
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
    //���չ�ʽ,��������1582��10��15��֮�������
    int w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7;
    //����w
    if (w < 0)
        w = w + 7;
    return w;
}
//�õ���һ������һ������
void _Date_::next_Monday(Date &date)
{
    //��ȡ���յ����ڡ�
    int week = get_week(date);
    //�������������ֱ������һ��
    if (week == 0)
    {
        add_a_day(date);
    }
    else
    {//�����������8-week�졣
        for (int i = 0; i < 8 - week; ++i)
        {
            add_a_day(date);
        }
    }
}