#include <string>
#include <stdexcept>
using namespace std;
class Date
{

public:
    class Bad_date
    {
    private:
        string msg;

    public:
        Bad_date(string _msg) : msg(_msg) {}
        Bad_date(const Bad_date &bad_date) { msg = bad_date.msg; }
        string get_msg() { return msg; }
    }; //exception class

    Date(int yy, int mm, int dd) throw(Bad_date); //Ĭ�ϲ���Ϊdefault_date�����ڣ��������쳣�׳�

    static bool right_date(const int &yy, const int &mm, const int &dd); //�жϸ����������Ƿ�Ϸ�

    static bool leap_year(int yy);

    static int get_days(int yy, int mm); //������ݡ��·ݵõ����µ�����

    static void set_default(int, int, int) throw(Bad_date);

    int get_day() const;

    int get_month() const;

    int get_year() const;

    string string_rep() const;

    void char_rep(char s[]) const throw(out_of_range); //ȷ��s���㹻���ڴ�ռ䣬�����ֶ��׳��쳣

    Date &add_year(int n);

    Date &add_month(int n);

    Date &add_day(int n);

    void add_a_day(Date &date);

    void add_a_month(Date &date);

    void add_a_year(Date &date);

private:
    int year, month, day; //year,month,day
    static Date default_date;
};
