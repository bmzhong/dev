#include <iostream>
#include<cstring>
using namespace std;
class String
{
public:
    char *str;
    String();
    String (char *s);
    String operator = (char *s);
}

String::String(char *s){
    if(str){
        delete [] str;
    }
    if(s){
        str=new char[strlen(s)];
        strcpy(str,s);
    }else{
        str=NULL;
    }
};

String::String(){
    
}

String::String(char *s){
    if(str){
        delete [] str;
    }
    if(s){
        str=new char[strlen(s)];
        strcpy(str,s);
    }else{
        str=NULL;
    }
};