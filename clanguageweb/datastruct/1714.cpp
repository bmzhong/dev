#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        a[0] = a[i];
        int j = i - 1;
        while (a[0] < a[j])
        {
            a[j + 1] = a[j];
            --j;   
        }
        a[j+1]=a[0];
    }
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}