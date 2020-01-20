#include<iostream>
using namespace std;
int main(){

}

void func(int n,int &s){
    if(n==1){
        s=1;
        return;
    }else{
        for(int i=1;i<n;++i){
            func(i,s);
            
        }
    }
}