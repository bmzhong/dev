#include <iostream>
using namespace std;
class complex
{
private:
    double re;
    double im;

public:
    complex(double _re = 0, double _im = 0) : re(_re), im(_im){};

    complex &operator+=(const complex &);

    complex &operator+=(const double &);

    complex &operator-=(const complex &);

    complex &operator-=(const double &);

    complex &operator*=(const complex &);

    complex &operator*=(const double &);

    complex &operator/=(const complex &);

    complex &operator/=(const double &);

    friend istream &operator>>(istream &, complex &);

    friend ostream &operator<<(ostream &, const complex &);

    friend complex operator+(const complex &, const complex &);

    friend complex operator+(const complex &, const double &);

    friend complex operator+(const double &, const complex &);

    friend complex operator-(const complex &, const complex &);

    friend complex operator-(const complex &, const double &);

    friend complex operator-(const double &, const complex &);

    friend complex operator*(const complex &, const complex &);

    friend complex operator*(const complex &, const double &);

    friend complex operator*(const double &, const complex &);

    friend complex operator/(const complex &, const complex &);

    friend complex operator/(const complex &, const double &);

    friend complex operator/(const double &, const complex &);

    friend bool operator==(const complex &, const complex &);

    friend bool operator!=(const complex &, const complex &);
};