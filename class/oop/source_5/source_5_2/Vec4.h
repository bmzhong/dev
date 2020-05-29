#include <iostream>
using namespace std;
class Vec4
{
private:
    float arr[4];

public:
    Vec4(float = 0.0, float = 0.0, float = 0.0, float = 0.0);

    Vec4 operator=(const Vec4 &);

    float operator[](const int &);

    Vec4 &operator+=(const Vec4 &);

    Vec4 &operator+=(const float &);

    Vec4 &operator-=(const Vec4 &);

    Vec4 &operator-=(const float &);

    Vec4 &operator*=(const Vec4 &);

    Vec4 &operator*=(const float &);

    Vec4 &operator/=(const Vec4 &);

    Vec4 &operator/=(const float &);

    friend Vec4 operator+(const Vec4 &, const Vec4 &);

    friend Vec4 operator+(const Vec4 &, const float &);

    friend Vec4 operator+(const float &, const Vec4 &);

    friend Vec4 operator-(const Vec4 &, const Vec4 &);

    friend Vec4 operator-(const Vec4 &, const float &);

    friend Vec4 operator-(const float &, const Vec4 &);

    friend Vec4 operator*(const Vec4 &, const Vec4 &);

    friend Vec4 operator*(const Vec4 &, const float &);

    friend Vec4 operator*(const float &, const Vec4 &);

    friend Vec4 operator/(const Vec4 &, const Vec4 &);

    friend Vec4 operator/(const Vec4 &, const float &);

    friend Vec4 operator/(const float &, const Vec4 &);

    friend ostream &operator<<(ostream &, const Vec4 &);
};