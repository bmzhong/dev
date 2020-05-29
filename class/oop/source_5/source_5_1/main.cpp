#include <iostream>
#include "complex.h"
using namespace std;

void testPlus()
{
    complex a(1.2, 2.1), b(3.2, 4.5);
    a += b;
    cout << "(1): " << a << endl;

    complex c(1, 2.5);
    c += 4;
    cout << "(2): " << c << endl;

    complex d(1, 2), e(3);
    cout << "(3): " << d + e << endl;

    complex f(2, 1);
    cout << "(4): " << f + 5 << endl;

    complex g(1, 2);
    cout << "(5): " << 2 + g << endl;
}

void testMinus()
{
    complex a(1, 2.2), b(3.1, 4);
    a -= b;
    cout << "(6): " << a << endl;

    complex c(1, 2);
    c -= 4.2;
    cout << "(7): " << c << endl;

    complex d(1, 2), e(3);
    cout << "(8): " << d - e << endl;

    complex f(2, 1);
    cout << "(9): " << f - 5 << endl;

    complex g(1, 2);
    cout << "(10): " << 2 - g << endl;
}

void testMultiply()
{
    complex a(1, 2), b(3, 4);
    a *= b;
    cout << "(11): " << a << endl;

    complex c(1, 2);
    c *= 4.45;
    cout << "(12): " << c << endl;

    complex d(1, 2), e(3);
    cout << "(13): " << d * e << endl;

    complex f(2, 1);
    cout << "(14): " << f * 5 << endl;

    complex g(1, 2);
    cout << "(15): " << 2 * g << endl;
}

void testDivide()
{
    complex a(1, 2), b(3, 4);
    a /= b;
    cout << "(11): " << a << endl;

    complex c(1, 2);
    c /= 4;
    cout << "(12): " << c << endl;

    complex d(1.5, 2), e(3);
    cout << "(13): " << d / e << endl;

    complex f(2, 1);
    cout << "(14): " << f / 5 << endl;

    complex g(1, 2);
    cout << "(15): " << 2 / g << endl;
}

void test1()
{
    complex a(1, 2), b(1, 3), c(2, 1), d(1, 2);
    cout << "(16): " << (a == b) << endl;
    cout << "(17): " << (a != b) << endl;
    cout << "(18): " << (a == c) << endl;
    cout << "(19): " << (a != c) << endl;
    cout << "(20): " << (a == d) << endl;
    cout << "(21): " << (a != d) << endl;
}

void test2()
{
    complex a(1,3),b(2,-1);
    cout<<"(22): " << +a <<endl;
    cout<<"(23): " << +b <<endl;
    cout<<"(24): " << -a<<endl;
    cout<<"(25): " << -b<<endl;
}

int main()
{
    testPlus();
    testMinus();
    testMultiply();
    testDivide();
    test1();
    test2();
    system("pause");
    return 0;
}