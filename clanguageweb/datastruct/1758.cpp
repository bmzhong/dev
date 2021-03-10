#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,k,a;
    vector<int> v;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k-1;++i){
        cout<<v[i]<<" ";
    }
    cout<<v[k-1]<<endl;
    system("pause");
    return 0;
}