#include<iostream>
using namespace std;
int main(){
    int k,n;
    cin>>n>>k;
    int a[n],b[k];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int j=0;j<k;++j){
        cin>>b[j];
        int f=0;
        for(int i=n-1;i>=0;--i){
            if(a[i]==b[j]){
                cout<<i<<" ";
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"-1 ";
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}