#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct A
{
    int arr;
    int time;
};
int main()
{
    int m, n, b, k = 0;
    int time = 0;
    A a;
    cin >> m >> n;
    vector<A> v;
    vector<queue<A>> q(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a.arr >> a.time;
        v.push_back(a);
    }
}