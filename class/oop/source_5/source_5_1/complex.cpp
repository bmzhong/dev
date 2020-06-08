#include "complex.h"
#include <cmath>

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

complex polar(const double &rho, const double &theta)
{
    complex r;
    r.re = rho * cos(theta);
    r.re = rho * sin(theta);
    return r;
}

complex conj(const complex &a)
{
    complex r;
    r.re = a.re;
    r.im = -a.im;
    return r;
}

double abs(const complex &a)
{
    double r = sqrt(a.re * a.re + a.im * a.im);
    return r;
}

double arg(const complex &a)
{
    double r = atan(a.im / a.re);
    return r;
}

double real(const complex &a)
{
    return a.re;
}

double imag(const complex &a)
{
    return a.im;
}
