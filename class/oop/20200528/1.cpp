#include <iostream>
using namespace std;
class Clock
{
private:
    int HOUR, MINUTE, SECOND;

public:
    Clock()
    {
        HOUR=0;
        MINUTE=0;
        SECOND=0;
    }

    void get(int &hour, int &minute, int *second)
    {
        hour = HOUR;
        minute = MINUTE;
        *second = SECOND;
    }

    void update()
    {
        if (SECOND >= 0 && SECOND < 59)
        {
            ++SECOND;
        }
        else
        {
            SECOND = 0;
            if (MINUTE >= 0 && MINUTE < 59)
            {
                ++MINUTE;
            }
            else
            {
                MINUTE = 0;
                if (HOUR >= 0 && HOUR < 23)
                {
                    ++HOUR;
                }
                else
                {
                    HOUR = 0;
                }
            }
        }
    }
    bool adjust(int h, int m, int s)
    {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
        {
            HOUR = h;
            MINUTE = m;
            SECOND = s;
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &os, const Clock &clock);
};
ostream &operator<<(ostream &os, const Clock &clock)
{
    os << clock.HOUR << ':' << clock.MINUTE << ':' << clock.SECOND;
    return os;
}
int main()
{

    int h, m, s;

    Clock testClock;

    testClock.get(h, m, &s);

    cout << "OUT-1: " << h << ":" << m << ":" << s << endl; // OUT-1: 0:0:0

    testClock.adjust(13, 5, 59);

    testClock.update();

    cout << "OUT-2: " << testClock << endl; // OUT-2: 13:6:0

    testClock.adjust(23, 59, 58);

    testClock.update();

    cout << "OUT-3: " << testClock << endl; // OUT-3: 23:59:59

    testClock.update();

    cout << "OUT-4: " << testClock << endl; // OUT-4: 0:0:0

    system("pause");
    return 0;
}