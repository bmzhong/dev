#include <iostream>
#include <map>
#include <string>
using namespace std;
class CStudent
{
public:
    struct CInfo
    {
        int id;
        string name;
    };
    int score;
    CInfo info;
};
int main()
{
    multimap<int, CStudent::CInfo> m;
    string cmd;
    CStudent st;
    while (cin >> cmd)
    {
        if (cmd == "Add")
        {
            cin >> st.info.name >> st.info.id >> st.score;
            m.insert(multimap<int, CStudent::CInfo>::value_type(st.score, st.info));
        }
        else if (cmd == "Query")
        {
            int score;
            cin >> score;
            multimap<int, CStudent::CInfo>::iterator p = m.lower_bound(score);
            if (p != m.begin())
            {
                --p;
                score = p->first;
                multimap<int, CStudent::CInfo>::iterator mp = p;
                int maxId = p->second.id;
                for (; p != m.begin() && p->first == score; --p)
                {
                    if (p->second.id > maxId)
                    {
                        mp = p;
                        maxId = p->second.id;
                    }
                }
                if (p->first == score)
                {
                    if (p->second.id > maxId)
                    {
                        mp = p;
                        maxId = p->second.id;
                    }
                }
                cout << mp->second.name << " " << mp->second.id << " " << mp->first << endl;
            }
            else
            {
                cout << "nobody" << endl;
            }
            system("pause");
            return 0;
        }
    }
}