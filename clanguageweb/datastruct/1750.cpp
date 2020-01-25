#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n,a;
    while(cin>>m>>n){
        vector<vector<int>> h;
        vector<int> v;
        for(int i=0;i<m;++i){
            int sum=0;
            int t=-99999;
            int k=0;
            for(int j=0;j<n;++j){
                cin>>a;
                if(a>t){
                    t=a;
                    k=j;
                }
                sum+=a;
                v.push_back(a);
            }
            v[k]=sum;
            h.push_back(v);
            v.clear();
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cout<<h[i][j]<<" ";
            }
            cout<<endl;
        }
        h.clear();
    }
    system("pause");
    return 0;
}