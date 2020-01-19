#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, a;
    vector<int> v, v1, v2;
    vector<vector<int>> h;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            v.push_back(a);
        }
        v1 = v;
        stable_sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size(); ++i)
        {
            auto it = find(v1.begin(), v1.end(), v[i]);
            a = distance(v1.begin(), it) + 1;
            v2.push_back(a);
        }
        h.push_back(v2);
        v2.clear();    
        v1.clear();
        v.clear();
    }
    for(int i=0;i<h.size();++i){
        for(int j=0;j<h[i].size()-1;++j){
            cout<<h[i][j]<<" ";
        }
        cout<<*h[i].rbegin()<<endl;
    }
    system("pause");
    return 0;
}