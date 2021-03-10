#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        v.push_back(a);
    }
    int k=1,t=v[0],m=1;
    for(int i=0;i<n;++i){
        if(v[i]>t){
            k++;
        }else{
            if(k>m){
                m=k;
            }
            k=1;
        }
        t=v[i];
    }
    cout<<m<<endl;
    system("pause");
    return 0;
}