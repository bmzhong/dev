#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,a,sum1=0,sum2=0;
    cin>>n;
    vector<int> v;
    vector<vector<int> > h;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a;
            if(i==j){
                sum1+=a;
            }
            if(i+j==n-1){
                sum2+=a;
            }
            v.push_back(a);
        }
        h.push_back(v);
        v.clear();
    }
    cout<<sum1<<endl;
    cout<<sum2<<endl;
    system("pause");
    return 0;
}