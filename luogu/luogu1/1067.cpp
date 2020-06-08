#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, coe;
    cin >> n;
    for (int i = n; i >= 0; --i)
    {
        cin >> coe;
        if (coe == 0)
            continue;
        if (i == n && i > 0)
        {
            if (coe > 0 && coe != 1)
                cout << coe;
            else if (coe < 0 && coe != -1)
                cout << coe;
            else if (coe == -1)
                cout << "-";
            if (n == 1)
                cout << "x";
            else if (n > 1)
                cout << "x^" << i;
        }
        else if (i == n && i == 0)
        {
            cout << coe;
        }
        else if(i>0)
        {
            if (coe > 0 && coe != 1)
                cout << "+" << coe;
            else if (coe < 0 && coe != -1)
                cout << coe;
            else if (coe == -1)
                cout << "-";
            else if (coe == 1)
                cout << "+";
            if (i > 1)
                cout << "x^" << i;
            else if (i == 1)
                cout << "x";
        }
        else if(i==0){
            if(coe>0)
                cout<<"+"<<coe;
            else
                cout<<coe;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}