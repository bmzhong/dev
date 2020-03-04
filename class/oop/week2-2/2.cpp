#include <iostream>
using namespace std;

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2, b = 3;
    cout << "a: " << a << " b: " << b << endl;
    swap1(&a, &b);
    cout << "a: " << a << " b: " << b << endl;

    int c = 2, d = 3;
    cout << "c: " << c << " d: " << d << endl;
    swap2(c, d);
    cout << "c: " << c << " d: " << d << endl;
    
    system("pause");
    return 0;
}
