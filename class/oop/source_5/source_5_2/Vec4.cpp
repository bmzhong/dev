#include "Vec4.h"

Vec4::Vec4(float a, float b, float c, float d)
{
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
}

Vec4 Vec4::operator=(const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] = a.arr[i];
    }
    return *this;
}

float Vec4::operator[](const int &i)
{
    return arr[i];
}

Vec4 &Vec4::operator+=(const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] += a.arr[i];
    }
    return *this;
}

Vec4 &Vec4::operator+=(const float &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] += a;
    }
    return *this;
}

Vec4 &Vec4::operator-=(const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] -= a.arr[i];
    }
    return *this;
}

Vec4 &Vec4::operator-=(const float &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] -= a;
    }
    return *this;
}

Vec4 &Vec4::operator*=(const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] *= a.arr[i];
    }
    return *this;
}

Vec4 &Vec4::operator*=(const float &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] *= a;
    }
    return *this;
}

Vec4 &Vec4::operator/=(const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] /= a.arr[i];
    }
    return *this;
}

Vec4 &Vec4::operator/=(const float &a)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] /= a;
    }
    return *this;
}

Vec4 operator+(const Vec4 &a, const Vec4 &b)
{
    Vec4 r = a;
    return r += b;
}

Vec4 operator+(const Vec4 &a, const float &b)
{
    Vec4 r=a;
    return r+=b;
}

Vec4 operator+(const float &a, const Vec4 &b)
{
    Vec4 r=b;
    return r+=a;
}

Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r = a;
    return r -= b;
}

Vec4 operator-(const Vec4 &a, const float &b)
{
    Vec4 r=a;
    return r-=b;
}

Vec4 operator-(const float &a, const Vec4 &b)
{
    Vec4 r;
    for (int i = 0; i < 4; i++)
    {
        r.arr[i]=a-b.arr[i];
    }
    return r;
}

Vec4 operator*(const Vec4 &a, const Vec4 &b)
{
    Vec4 r = a;
    return r *= b;
}

Vec4 operator*(const Vec4 &a, const float &b)
{
    Vec4 r=a;
    return r*=b;
}

Vec4 operator*(const float &a, const Vec4 &b)
{
    Vec4 r=b;
    return r*=a;
}

Vec4 operator/(const Vec4 &a, const Vec4 &b)
{
    Vec4 r = a;
    return r /= b;
}

Vec4 operator/(const Vec4 &a, const float &b)
{
    Vec4 r=a;
    return r/=b;
}

Vec4 operator/(const float &a, const Vec4 &b)
{
    Vec4 r;
    for (int i = 0; i < 4; i++)
    {
        r.arr[i]=a/b.arr[i];
    }
    return r;
}

ostream &operator<<(ostream &os, const Vec4 &a)
{
    for (int i = 0; i < 4; i++)
    {
        os<<a.arr[i]<<" ";
    }
    return os;
}