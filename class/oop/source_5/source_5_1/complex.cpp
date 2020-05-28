#include "complex.h"

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
    re = re * a.re - im * a.im;
    im = re * a.im + im * a.re;
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
    re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
    im = (im * a.re - re * a.im) / (a.re * a.re + a.im * a.im);
    return *this;
}

complex &complex::operator/=(const double &a)
{
    re /= a;
    im /= a;
    return *this;
}

istream &operator>>(istream &, complex &);

ostream &operator<<(ostream &, const complex &);

complex operator+(const complex &, const complex &);

complex operator+(const complex &, const double &);

complex operator+(const double &, const complex &);

complex operator-(const complex &, const complex &);

complex operator-(const complex &, const double &);

complex operator-(const double &, const complex &);

complex operator*(const complex &, const complex &);

complex operator*(const complex &, const double &);

complex operator*(const double &, const complex &);

complex operator/(const complex &, const complex &);

complex operator/(const complex &, const double &);

complex operator/(const double &, const complex &);

bool operator==(const complex &, const complex &);

bool operator!=(const complex &, const complex &);