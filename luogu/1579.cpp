#include <iostream>
#include <cmath>
using namespace std;
bool prime(int a);
int main()
{
    int n;
    int h[6000];
    cin >> n;
    int k=0;
    for (int i = 2; i < n; ++i)
    {
        if (prime(i))
        {
            h[k++]=i;
        }
    }
    int f=0;
    int p;
    for(int i=0;i<k;++i){
        for(int j=i;j<k;++j){
            for(int p=k-1;p>=j;--p){
                if(h[i]+h[j]+h[p]==n){
                    cout<<h[i]<<" "<<h[j]<<" "<<h[p]<<endl;
                    f=1;
                    break;
                }
            } 
            if(f==1){
                f=2;
                break;
            } 
        }
        if(f==2){
            f=3;
            break;
        }
    }
    system("pause");
    return 0;
}

bool prime(int a)
{
    if (a % 2 == 0&&a!=2)
    {
        return false;
    }
    int r = int(sqrt(a));
    for (int i = 2; i <= r; ++i)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}