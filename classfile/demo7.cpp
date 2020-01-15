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
    friend ostream & operator << (ostream &os,Complex &c);
    friend istream & operator >> (istream &is,Complex &c);
};

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
    Complex c;
    cin>>c;
    cout<<c;
    system("pause");
    return 0;
}