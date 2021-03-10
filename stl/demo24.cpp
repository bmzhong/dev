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
    vector<vector<int>> m;
    m.push_back(v1);
    m.push_back(v2);
    vector<vector<int>>().swap(m);
    cout << m.size() << endl;
    cout << m.capacity() << endl;

    system("pause");
    return 0;
}