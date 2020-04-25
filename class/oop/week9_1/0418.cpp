#include <iostream>
using namespace std;

struct X
{

    int i;

    X(int);

    X operator+(int);
};

X::X(int j) : i(j) {}

X X::operator+(int j)
{
    i += j;
    return *this;
}

struct Y
{

    int i;

    Y(X);

    Y operator+(X);

    operator int();
};

Y::Y(X x) : i(x.i) {}

Y Y::operator+(X x)
{
    i += x.i;
    return *this;
}

Y::operator int()
{
    return i;
}

extern X operator*(X, Y);

extern int f(X);

X operator*(X x, Y y)
{
    return X(x.i * y.i);
}

int f(X x)
{
    return x.i;
}

X x = 1;

Y y = x;

int i = 2;

int main()

{

    cout << "(1):i+10:  " << i + 10 << endl; //(1)

    // y + 10; //(2)

    // y + 10 * y; //(3)

    cout << "(4): x + y + i:    " << (x + y + i).i << endl; //(4)

    cout << "(5): x *x + i:     " << (x * x + i).i << endl; //(5)

    cout << "(6): f(7):     " << f(7) << endl; //(6)

    // f(y); //(7)

    cout << "(8): y+y:  " << y + y << endl; //(8)

    cout<<"(9): 10 + y:     "<<10 + y<<endl; //(9)

    system("pause");
    return 0;
}