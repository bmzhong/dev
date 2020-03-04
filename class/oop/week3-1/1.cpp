#include<iostream>
#include<string>
using namespace std;
int main(){

    char ch='s';
    char * pch=&ch;//(1) a pointer to a character

    int arr[5]={1,2,3,4,5};//(2)  an array of 5 intergers

    int (&rearr)[5]=arr;//(3) a refrence to an array of 5 integers;

    char * brr[5]={"aaa","bbb","ccc","ddd","eee"};
    char * * pbrr=brr;//(4) a pointer to an array of character strings

    char  c='1';
    char * pc=&c;
    char ** ppc=&pc;//(5) a pointer to a pointer of a character;

    const int a=1;//(6) a constant integer

    const int *pa=&a;//(7) a pointer to a constant integer
    
    int b=2;
    int * const pb=&b;// (8) a constant pointer to an integer

    system("pause");
    return 0;
}