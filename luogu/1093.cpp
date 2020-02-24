#include <iostream>
#include <algorithm>
using namespace std;
struct A
{
    int che, eng, math, score,id;
};
A a[301];
int n;
bool cmp(const A a1, const A a2)
{
    if (a1.score == a2.score)
    {
        if (a1.che == a2.che)
        {
            return a1.id < a2.id;
        }
        return a1.che > a2.che;
    }
    return a1.score > a2.score;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].che >> a[i].math >> a[i].eng;
        a[i].score = a[i].che + a[i].math + a[i].eng;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i=1;i<=5;++i){
        cout<<a[i].id<<" "<<a[i].score<<endl;
    }
    system("pause");
    return 0;
}