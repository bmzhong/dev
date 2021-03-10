#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Complex{
    public:
    int real;
    int imag;
    Complex(){}
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    operator int(){
        return real;
    }
    Complex operator ++ ();
    Complex operator ++ (int);
    friend Complex operator -- (Complex &c);
    friend Complex operator -- (Complex &c,int);
    friend ostream & operator << (ostream &os,Complex &c);
    friend istream & operator >> (istream &is,Complex &c);
};

Complex Complex::operator ++(){
    ++real;
    return *this;
}

Complex Complex::operator ++ (int){
    Complex f=*this;
    ++real;
    return f;
}

Complex operator -- (Complex &c){
    --c.real;
    return c;
}

Complex operator -- (Complex &c,int){
    Complex f(c);
    --c.real;
    return f;
}

ostream & operator << (ostream &os,Complex &c){
        os<<c.real<<"+"<<c.imag<<"i"<<endl;
        return os;
}

istream & operator >> (istream &is,Complex &c){
        string str;
        cin>>str;
        int pos=str.find("+");
        string str1,str2;
        str1=str.substr(0,pos);
        str2=str.substr(pos+1);
        stringstream s;
        s<<str1;
        s>>c.real;
        s.clear();
        s<<str2;
        s>>c.imag;
        s.clear();
        return is;
}
int main(){
    // Complex c;
    // int n;
    // cin>>c>>n;
    // cout<<c<<n<<endl;
    // cout<<(int)c<<endl;
    Complex c1(3,3),c2(c1),c3(c1),c4(c1);
    c1--;
    cout<<c1<<endl;              
    cout<<(++c2)<<endl;
    cout<<(c3--)<<endl;
    cout<<(--c4)<<endl;
    system("pause");
    return 0;
}