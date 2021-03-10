#include <iostream>
#include<cstring>
using namespace std;
class String
{
public:
    char *str;
    const char * c_str(){
        return str;
    }
    String();
    String(const char *s);
    String & operator = (char *s);
    friend int add(int a,int b);
    
};


int add(int a,int b){
    return a+b;
}

String::String(const char *s){
    if(s){
        str=new char[strlen(s)];
        strcpy(str,s);
    }else{
        str=NULL;
    }
};

String::String(){
    
}

String & String::operator = (char *s){
    if(str){
        delete [] str;
    }
    if(s){
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }else{
        str=NULL;
    }
}

int main(){
    String s="hello",s1;
    s1="world";
    cout<<s1.c_str()<<endl;
    cout<<s.c_str()<<endl;
    cout<<add(2,3)<<endl;
    system("pause");
    return 0;
}
