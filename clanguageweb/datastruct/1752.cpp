#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, n;
    vector<int> v;
    vector<vector<int>> e;
    vector<vector<vector<int>>> h;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a;
                v.push_back(a);
            }
            e.push_back(v);
            v.clear();
        }
        h.push_back(e);
        e.clear();
    }
    int t;
    for (int i = 0; i < h.size(); ++i)
    {
        t = h[i].size();
        int flag=1;
        for (int j = 0; j < t; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                if(h[i][j][k]!=h[i][k][j]){
                    flag=0;
                }
            }
        }
        if(flag==0){
            cout<<"No!"<<endl;
        }else{
            cout<<"Yes!"<<endl;
        }
    }
    system("pause");
    return 0;

}