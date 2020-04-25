#include <iostream>
using namespace std;
// int fun(int &a){
//     return a;
// }
class complex
{

    double re, im;

public:
    complex(double r = 0, double i = 0) : re(r), im(i) {
        cout<<"hello"<<endl;
    }

    complex(const complex &a) : re(a.re), im(a.im) {}

    operator double() const { return re; }

    complex &operator+=(complex a);

    complex operator+(complex a);

    friend ostream &operator<<(ostream &oo, const complex &a);
};
int main()
{
    // complex cxa(1.3, -2), cxb = 2.5, cxc = {1, -1};
    int i = 5;
    double d = 0;
    complex a;
    a=12;
    // cout<<typeid(10+cxa).name()<<endl;
    system("pause");
    return 0;
}