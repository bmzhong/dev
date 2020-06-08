#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> p1[2501], p2[2501];
priority_queue<int, vector<int>, greater<int> > a;
bool cmp(const pair<int, int> &a1, const pair<int, int> &a2)
{

    if (a1.first == a2.first)
        return a1.second < a2.second;
    return a1.first < a2.first;
}
int main()
{
    int c, l, res = 0;
    scanf("%d%d", &c, &l);
    for (int i = 0; i < c; ++i)
    {
        scanf("%d%d", &p1[i].first, &p1[i].second);
    }
    for (int i = 0; i < l; ++i)
    {
        scanf("%d%d", &p2[i].first, &p2[i].second);
    }
    sort(p1, p1 + c, cmp);
    sort(p2, p2 + l, cmp);
    int j = 0;
    for (int i = 0; i < l; ++i)
    {
        while (j < c && p1[j].first <= p2[i].first)
        {
            a.push(p1[j].second);
            ++j;
        }
        while(p2[i].second&&!a.empty()){
            int temp=a.top();
            a.pop();
            if(temp>=p2[i].first){
                ++res;
                --p2[i].second;
            }
        }
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}