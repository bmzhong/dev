#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
    int m, n;
    cin >> m;
    string str;
    vector<string> v;
    vector<vector<string>> h;
    for (int i = 0; i < m; ++i)
    {
        cin >> n;
        cin.get();
        for (int j = 0; j < n; ++j)
        {
            getline(cin, str);
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        h.push_back(v);
        v.clear();
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<h[i].size();++j){
            cout<<h[i][j]<<endl;
        }
    }
    system("pause");
    return 0;
}