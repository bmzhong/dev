#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n],b[k];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<k;++i){
        cin>>b[i];
        int low=0,high=n-1,mid;
        while(low<high){
            mid=(low+high)/2;
            if(a[mid]==b[i]){
                while(a[mid]==b[i]){mid--;}
                cout<<++mid<<" ";
                break;
            }else if(a[mid]<b[i]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        if(a[mid]!=b[i]){
            cout<<"-1 ";
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}