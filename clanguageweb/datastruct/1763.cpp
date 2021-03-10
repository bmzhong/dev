#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void func(vector<int> m1, vector<int> m2, vector<vector<int>> &h);
int main()
{
    int m, n;
    vector<vector<int>> h1;
    vector<vector<vector<int>>> h;
    vector<int> m1;
    vector<int> m2;
    int a;
    while (cin >> m)
    {
        m1.clear();
        m2.clear();
        for (int i = 0; i < m; ++i)
        {
            cin >> a;
            m1.push_back(a);
        }
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            m2.push_back(a);
        }
        func(m1,m2,h1);
        h.push_back(h1);
    }
    for(int i=0;i<h.size();++i){
        for(int j=0;j<h[i].size();++j){
            for(int k=0;k<h[i][j].size()-1;++k){
                cout<<h[i][j][k]<<" ";
            }
            cout<<*h[i][j].rbegin()<<endl;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}

void func(vector<int> m1, vector<int> m2, vector<vector<int>> &h)
{
    h.clear();
    h.push_back(m1);
    h.push_back(m2);
    for (int i = 0; i < m2.size(); ++i)
    {
        if (!count(m1.begin(), m1.end(), m2[i]))
        {
            m1.push_back(m2[i]);
        }
        h.push_back(m1);
    }
}
//17 18行记得先清空m1,m2;