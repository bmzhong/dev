#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    string str("");
    for(int i=1;i<=9;++i){
        cin>>b;
        if(b!=0){
            str.append(b,char(i+'0'));
        }
    }
    int pos=str.find_first_not_of("0");
    str.insert(pos+1,a,'0');
    cout<<str<<endl;
    system("pause");
    return 0;
}
