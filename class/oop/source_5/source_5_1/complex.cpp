#include "complex.h"

complex complex::operator=(const complex &a)
{
    re = a.re;
    im = a.im;
    return *this;
}

complex &complex::operator+=(const complex &a)
{
    re += a.re;
    im += a.im;
    return *this;
}

complex &complex::operator+=(const double &a)
{
    re += a;
    return *this;
}

complex &complex::operator-=(const complex &a)
{
    re -= a.re;
    im -= a.im;
    return *this;
}

complex &complex::operator-=(const double &a)
{
    re -= a;
    return *this;
}

complex &complex::operator*=(const complex &a)
{
    double temp = re;
    re = re * a.re - im * a.im;
    im = temp * a.im + im * a.re;
    return *this;
}

complex &complex::operator*=(const double &a)
{
    re *= a;
    im *= a;
    return *this;
}

complex &complex::operator/=(const complex &a)
{
    double temp = re;
    re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
    im = (im * a.re - temp * a.im) / (a.re * a.re + a.im * a.im);
    return *this;
}

complex &complex::operator/=(const double &a)
{
    re /= a;
    im /= a;
    return *this;
}

complex operator+(complex &a)
{
    a.re = +a.re;
    a.im = +a.im;
    return complex(a.re, a.im);
}

complex operator-(complex &a)
{
    a.re = -a.re;
    a.im = -a.im;
    return complex(a.re, a.im);
}

istream &operator>>(istream &is, complex &a)
{
    is >> a.re >> a.im;
    return is;
}

ostream &operator<<(ostream &os, const complex &a)
{
    if (a.im >= 0)
        os << a.re << "+" << a.im << "i ";
    else
        os << a.re << a.im << "i ";
    return os;
}

complex operator+(const complex &a, const complex &b)
{
    complex c = a;
    return c += b;
}

complex operator+(const complex &a, const double &b)
{
    complex c = a;
    return c += b;
}

complex operator+(const double &a, const complex &b)
{
    complex c = b;
    return c += a;
}

complex operator-(const complex &a, const complex &b)
{
    complex c = a;
    return c -= b;
}

complex operator-(const complex &a, const double &b)
{
    complex c = a;
    return c -= b;
}

complex operator-(const double &a, const complex &b)
{
    complex c = a;
    return c -= b;
}

complex operator*(const complex &a, const complex &b)
{
    complex c = a;
    return c *= b;
}

complex operator*(const complex &a, const double &b)
{
    complex c = a;
    return c *= b;
}

complex operator*(const double &a, const complex &b)
{
    complex c = b;
    return c *= a;
}

complex operator/(const complex &a, const complex &b)
{
    complex c = a;
    return c /= b;
}

complex operator/(const complex &a, const double &b)
{
    complex c = a;
    return c /= b;
}

complex operator/(const double &a, const complex &b)
{
    complex c = a;
    return c /= b;
}

bool operator==(const complex &a, const complex &b)
{
    if (a.re == b.re && a.im == b.im)
        return true;
    return false;
}

bool operator!=(const complex &a, const complex &b)
{
    return !(a == b);
}