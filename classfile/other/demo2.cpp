#include<iostream>
using namespace std;
class Complex{
    private:
        int real;
        int image;
    public:
        int getreal(){
            return real;
        }
        inline int getImage(){
            return image;
        }
        Complex(int _real,int _image);
        Complex(int _real);
        Complex();
        Complex(Complex c1,Complex c2);
        Complex(const Complex &c1){
            cout<<"复制构造函数"<<endl;
            real=c1.real;
            image=c1.image;
        }
};

Complex::Complex(int _real){
    cout<<"real构造函数"<<endl;
    real=_real;
}

Complex::Complex(){
    cout<<"默认构造函数"<<endl;
}

Complex::Complex(Complex c1,Complex c2){
    cout<<"构造函数c1c2"<<endl;
    real=c1.real+c2.real;
    image=c1.image+c2.image;
}

Complex::Complex(int _real,int _image){
    cout<<"构造函数real image"<<endl;
    real=_real;
    image=_image;
}

Complex func(){
    cout<<"我是一个函数"<<endl;
    Complex a(4);
    return a;
}

int main(){
    Complex p1[2];
    Complex p2[2]={2,3};
    Complex p3[3]={1,Complex(1,2)};
    cout<<"-----------------------------"<<endl;
    Complex *p=new Complex[2];
    delete [] p;
    cout<<"=============================="<<endl;
    Complex *p4[4]={new Complex,new Complex};
    cout<<"+++++++++++++++++++++++++++++++"<<endl;
    Complex p5,p7;
    p7=p5;
    cout<<"99999999999999999999999999999999"<<endl;
    Complex a=func();
    system("pause");
    return 0;
}