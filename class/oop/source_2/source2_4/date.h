namespace _Date_
{

    using namespace std;
    struct Date
    {
        int year;
        int month;
        int day;
    };

    const char *weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday"};
//判断是否是闰年
    bool leap_year(int year);
//传入年份、月份得到当月的天数
    int get_days(int year, int month);
//输入日期
    void input(Date &date);
//输出日期
    void display(const Date &date);
//增加一天后的新日期
    void add_a_day(Date &date);
//增加一个月的新日期
    void add_a_month(Date &date);
//增加一年后的新日期
    void add_a_year(Date &date);
//根据年月日返回星期
    int get_week(Date date);
//得到下一个星期一的日期
    void next_Monday(Date &date);
} // namespace Date
