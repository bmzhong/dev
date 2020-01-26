#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> s;
    int n, a;
    while (cin >> n && n >= 1 && n < 1000)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            s.push_back(a);
        }
        if (n == 1)
        {
            cout << s[0] << endl;
            cout << "-1" << endl;
        }
        else
        {
            auto it=max_element(s.begin(),s.end());
            cout<<*it<<endl;
            s.erase(it);
            sort(s.begin(),s.end());
            for (auto it : s)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        vector<int>().swap(s);
    }
    system("pause");
    return 0;
}
