#include <iostream>
#include "Vec4.h"
using namespace std;

void testPlus()
{
    Vec4 a(1.1, 1.2, 1.3, 1.4), b(2.1, 2.2, 2.3, 2.4);
    a += b;
    cout << "(1): " << a << endl;

    Vec4 c(1.1, 1.2, 1.3, 1.4);
    c += 4;
    cout << "(2): " << c << endl;

    Vec4 d(1.1, 1.2, 1.3, 1.4), e(2.1, 2.2, 2.3, 2.4);
    cout << "(3): " << d + e << endl;

    Vec4 f(1.1, 1.2, 1.3, 1.5);
    cout << "(4): " << f + 5 << endl;

    Vec4 g(1.1, 2.1, 3.1, 4.1);
    cout << "(5): " << 2 + g << endl;
}

void testMinus()
{
    Vec4 a(1.1, 1.2, 1.3, 1.4), b(2.1, 2.2, 2.3, 2.4);
    a -= b;
    cout << "(6): " << a << endl;

    Vec4 c(1.1, 1.2, 1.3, 1.4);
    c -= 4.2;
    cout << "(7): " << c << endl;

    Vec4 d(1.1, 1.2, 1.3, 1.4), e(2.1, 2.2, 2.3, 2.4);
    cout << "(8): " << d - e << endl;

    Vec4 f(1.1, 1.2, 1.3, 1.5);
    cout << "(9): " << f - 5 << endl;

    Vec4 g(1.1, 2.1, 3.1, 4.1);
    cout << "(10): " << 2 - g << endl;
}

void testMultiply()
{
    Vec4 a(1.1, 1.2, 1.3, 1.4), b(2.1, 2.2, 2.3, 2.4);
    a *= b;
    cout << "(11): " << a << endl;

    Vec4 c(1.1, 1.2, 1.3, 1.4);
    c *= 4.45;
    cout << "(12): " << c << endl;

    Vec4 d(1.1, 1.2, 1.3, 1.4), e(2.1, 2.2, 2.3, 2.4);
    cout << "(13): " << d * e << endl;

    Vec4 f(1.1, 1.2, 1.3, 1.5);
    cout << "(14): " << f * 5 << endl;

    Vec4 g(1.1, 2.1, 3.1, 4.1);
    cout << "(15): " << 2 * g << endl;
}

void testDivide()
{
    Vec4 a(1.1, 1.2, 1.3, 1.4), b(2.1, 2.2, 2.3, 2.4);
    a /= b;
    cout << "(11): " << a << endl;

    Vec4 c(1.1, 1.2, 1.3, 1.4);
    c /= 4;
    cout << "(12): " << c << endl;

    Vec4 d(1.1, 1.2, 1.3, 1.4), e(2.1, 2.2, 2.3, 2.4);
    cout << "(13): " << d / e << endl;

    Vec4 f(1.1, 1.2, 1.3, 1.5);
    cout << "(14): " << f / 5 << endl;

    Vec4 g(1.1, 2.1, 3.1, 4.1);
    cout << "(15): " << 2 / g << endl;
}

int main()
{
    testPlus();
    testMinus();
    testMultiply();
    testDivide();
    system("pause");
    return 0;
}