#include <iostream>
#include "itoa.cpp"

using namespace std;

int main()
{
    int test;
    int base;
    while (cin >> test >> base)
    {
        char ch[100];
        my_itoa::itoa(test, ch, base);
        cout << ch << endl;
    }

    system("pause");
    return 0;
}
