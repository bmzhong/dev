#include <iostream>
#include "itoa.cpp"

using namespace std;

int main()
{
    int test;
    while (cin >> test)
    {
        char ch[100];
        my_itoa::itoa(test, ch, 8);
        cout << ch << endl;
    }

    system("pause");
    return 0;
}
