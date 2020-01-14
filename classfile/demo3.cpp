#include <iostream>
using namespace std;
class Complex
{
public:
    static int real;
    char *c;
    int imag;
    int f1();
    static int f2();
    void f3() const;
    Complex(int _real)
    {
        cout << "类型转换构造函数" << endl;
        real = _real;
        imag = 0;
    }
    Complex(int _real, int _imag)
    {
        cout << "有两个参数的构造函数" << endl;
        real = _real;
        imag = _imag;
    }
    Complex()
    {
    }
    ~Complex();
};

void Complex::f3() const{
    cout<<"hello world"<<endl;
}

int Complex::f1()
{
    return 1;
}

int Complex::f2()
{
    return 2;
}

int Complex::real = 0;
Complex::~Complex()
{
    cout << "我是析构函数" << endl;
}

Complex func(Complex c)
{
    cout << "我是一个函数" << endl;
    Complex d;
    return d;
}

int main()
{
    const Complex q;
    q.f3();
    cout<<"------------------------"<<endl;
    cout << Complex::f2() << endl;
    Complex *p1 = new Complex(4, 5);
    Complex *p = new Complex[2];
    delete[] p;
    delete p1;
    Complex a;
    cout << "------------------------" << endl;
    Complex d = func(a);
    system("pause");
    return 0;
}
