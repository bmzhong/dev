#include <iostream>
using namespace std;
class Complex
{
private:
    int real;
    int imag;

public:
    Complex(){

    }
    int getReal(){
        return real;
    }
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    Complex operator+(Complex c1);
    friend Complex operator+(int a, Complex c1);
};
Complex Complex::operator+(Complex c1)
{
    real += c1.real;
    imag += c1.imag;
    return *this;
}

Complex operator + (int a,Complex c1){
    Complex c;
    c.real=a+c1.real;
    c.imag=c1.imag;
    return c;
}

int main(){
    Complex c(1,2),c1(1,5);
    c=2+c;
    c=c+c1;
    cout<<c.getReal()<<endl;
    system("pause");
    return 0;
}