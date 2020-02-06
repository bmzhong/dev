#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    set<int> s;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        s.insert(a);
    }
    int m = s.size();
    cout << m << endl;
    for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
