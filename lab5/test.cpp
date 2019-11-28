#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;
typedef struct Data {
    string name;
    string phone;
    string site;
} Data,*PData;
typedef struct Node {
    Data data;
    struct Node *next;
} Node,*PNode;
int main(){
    PNode p;
    p=new Node;
    string str="fdafa";
    string str1="fdafa";
    p->data.name=str;
    return 0;
}
