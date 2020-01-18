#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1, v2;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(7);
    v2 = v1;
    // vector<int>().swap(v1);
    // cout<<v1.size()<<endl;
    // cout<<v1.capacity()<<endl;
    vector<vector<int>> m;
    for (int i = 0; i < 4; ++i)
    {
        v1.push_back(5);
        v1.push_back(5);
        m.push_back(v1);
        m.push_back(v2);
        vector<vector<int>>().swap(m);
        cout << m.size() << endl;
        cout << m.capacity() << endl;
    }
    system("pause");
    return 0;
}