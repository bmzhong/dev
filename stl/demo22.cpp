#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class A
{
public:
    int v;
    A(int n) : v(n) {}
    A() { v = 0; }
};
bool operator<(const A &a1, const A &a2)
{
    return a1.v < a2.v;
}

ostream &operator<<(ostream &os, const A &a)
{
    os << a.v << ",";
    return os;
}

template <class T>
void print(T first, T last)
{
    for (; first != last; ++first)
    {
        cout << *first << " ";
    }
    cout << endl;
}
int main()
{
    A a[7] = {1, 2, 2, 3, 3, 5, 6};
    A b[3] = {3, 4, 6};
    A c[20];
    A d[4] = {2, 2, 2, 3};
    A e[6] = {2, 2, 2, 3, 7, 7};
    cout << boolalpha;
    cout << "1) " << binary_search(a, a + 7, A(3)) << endl;
    cout << "2) " << binary_search(a, a + 7, A(100)) << endl;
    cout << "3) " << includes(a, a + 7, b, b + 3) << endl;
    A *p = lower_bound(a, a + 7, 3);
    cout << "4) " << p - a << endl;
    p = upper_bound(a, a + 7, 3);
    cout << "5) " << p - a << endl;
    pair<A *, A *> pi = equal_range(a, a + 7, 3);
    cout << "6) " << pi.first - a << "," << pi.second - a << endl;
    print(a, a + 7);
    print(b, b + 3);
    merge(a, a + 7, b, b + 3, c);
    print(c, c + 10);
    memset(c, 0, sizeof(c));
    p = set_union(a, a + 7, d, d + 4, c);
    print(c, c + 11);
    memset(c, 0, sizeof(c));
    p = set_intersection(a, a + 7, d, d + 4, c);
    print(c, c + 11);
    memset(c, 0, sizeof(c));
    p = set_difference(a, a + 7, d, d + 4, c);
    print(c, c + 11);
    memset(c, 0, sizeof(c));
    p=set_symmetric_difference(a,a+7,e,e+6,c);
    print(c,c+13);
    A f[8]={2,4,6,8,1,3,5,7};
    inplace_merge(f,f+4,f+8);
    print(f,f+8);
    system("pause");
    return 0;
}