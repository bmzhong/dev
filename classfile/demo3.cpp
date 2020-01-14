#include<iostream>
using namespace std;
class Complex{
    public:
        static int real;
        char *c;
        int imag;
    Complex(int _real){
        cout<<"我是类型转换构造函数"<<endl;
        real=_real;
        imag=0;
    }
    Complex(int _real,int _imag){
        cout<<"我是有两个参数的构造函数"<<endl;
        real=_real;
        imag=_imag;
    }
    Complex(){

    }
    ~Complex();
};
Complex::~Complex(){
    cout<<"我是析构函数"<<endl;
}

Complex func(Complex c){
    cout<<"我是一个函数"<<endl;
    Complex d;
    return d;

}

int main(){
    cout<<Complex::real<<endl;
    Complex *p1=new Complex(4,5);
    Complex *p=new Complex[2];
    delete [] p;
    delete p1;
    Complex a;
    cout<<"------------------------"<<endl;
    Complex d=func(a);
    system("pause");
    return 0;
}
