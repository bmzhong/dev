#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=2;i<=n;++i){
        a[0]=a[i];
        int x=1,y=i-1,mid=(x+y)/2;
        while(x<=y){
            mid=(x+y)/2;
            if(a[mid]>a[0]){
                y=mid-1;
            }else{
                x=mid+1;
            }
        }
        for(int j=i-1;j>y;--j){
            a[j+1]=a[j];
        }
        a[y+1]=a[0];
    }
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;

}