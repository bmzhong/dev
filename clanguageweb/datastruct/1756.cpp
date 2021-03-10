#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    vector<int> v, v1, v2;
    vector<vector<int>> h;
    while (cin >> a)
    {
        if (a % 2 == 1)
        {
            v1.push_back(a);
        }
        else
        {
            v2.push_back(a);
        }
        for (int i = 0; i < 9; ++i)
        {
            cin>>a;
            if (a % 2 == 1)
            {
                v1.push_back(a);
            }
            else
            {
                v2.push_back(a);
            }
        }
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end());
        v.insert(v.begin(),v1.begin(),v1.end());
        v.insert(v.end(),v2.begin(),v2.end());
        h.push_back(v);
        v1.clear();
        v2.clear();
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
