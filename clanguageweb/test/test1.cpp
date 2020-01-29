#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    list<int> v = {1, 1, 1, 1, 1, 2, 1, 1};
    while (next_permutation(v.begin(), v.end()))
    {
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}