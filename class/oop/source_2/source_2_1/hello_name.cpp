#include<iostream>
using namespace std;
int main(int argc,char * argv[]){
    if(argc<=1)
        return 0;
    for(int i=1;i<=argc;++i){
        cout<<"Hello,"<<argv[i]<<"!"<<endl;
    }
    system("pause");
    return 0;
}