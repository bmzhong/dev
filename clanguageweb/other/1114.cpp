#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int a;
    for (int i = 0; i < 4; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int k = 3;
    for (int i = 0; i < 4; ++i)
    {
        vector<int> h;
        for (int j = 0; j < 4; ++j)
        {
            if (j != k)
            {
                h.push_back(v[j]);
            }
        }
        sort(h.begin(), h.end());
        for (int j = 0; j < 3; ++j)
        {
            cout << h[j] << " ";
        }
        cout << endl;
        while (next_permutation(h.begin(), h.end()))
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << h[j] << " ";
            }
            cout << endl;
        }
        --k;
    }

    system("pause");
    return 0;
}