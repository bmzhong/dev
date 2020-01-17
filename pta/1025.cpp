#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct A
{
    string ad;
    int data;
    string next;
};

bool operator==(const A a2, string next)
{
    return next == a2.ad;
}

ostream &operator<<(ostream &os, A &a)
{
    os << a.ad << " " << a.data << " " << a.next << endl;
    return os;
}

int main()
{
    int first, n, k;
    cin >> first >> n >> k;
    vector<A> v, p;
    A a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a.ad >> a.data >> a.next;
        v.push_back(a);
    }
    int j = n;
    int next = first;
    vector<A>::iterator it;
    while (j > 0)
    {
        it = find(v.begin(), v.end(), next);
        next = it->next;
        p.push_back(*it);
        --j;
    }
    cout<<"++++++++++++++++++++++++++++++"<<endl;
    for (auto it : p)
    {
        cout << it;
    }
    v.clear();
    int d = n / k;
    j = 0;
    cout << "------------------------------- " << endl;
    while (j < d)
    {
        int w = 4 + j * k;
        while ((w - j * k) > 0)
        {
            v.push_back(p[w - 1]);
            --w;
        }
        ++j;
    }
    int e = k * (n / k);
    for (int i = e; i < n; ++i)
    {
        v.push_back(p[i]);
    }
    for (int i = 0; i < v.size() - 1; ++i)
    {
        v[i].next = v[i + 1].ad;
    }
    v.rbegin()->next = -1;
    for (auto it : v)
    {
        cout << it;
    }
    system("pause");
    return 0;
}