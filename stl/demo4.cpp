#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(const vector<T> &v)
{
    for (auto i = v.begin(); i < v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    print(v);
    cout << v.end() - v.begin() << endl;
    v.insert(v.begin() + 2, 13);
    print(v);
    v.erase(v.begin() + 2);
    print(v);
    vector<int> v2(4, 100);
    v2.insert(v2.begin(), v.begin() + 1, v.end() - 1);
    print(v2);
    v.erase(v.begin() + 1, v.end() - 2);
    print(v);
    cout << "-----------------------------------------------------------" << endl;
    vector<vector<int>> v3(3);
    for (int i = 0; i < v3.size(); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            v3[i].push_back(j*i);
        }
    }
    for (int i = 0; i < v3.size(); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout<<v3[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}