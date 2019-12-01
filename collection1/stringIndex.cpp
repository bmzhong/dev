#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
    int n;
    string string1[120][2];
    int m[120];
    int i=0;
    while(cin>>string1[i][0]&&cin>>string1[i][1]){
        int pos=string1[i][0].find(string1[i][1]);
        int flag=1;
        for (int j = 0; j < string1[i][1].length(); ++j) {
            if(string1[i][0][j+pos]!=string1[i][1][j]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            m[i]=string::npos;
        }else{
            m[i]=pos;
        }
        
        ++i;
        flag=1;
    }
    for (int j = 0; j < i; ++j) {
        if (m[j]==string::npos){
            cout<<0<<endl;
        }else{
            cout<<m[j]+1<<endl;
        }
    }
    return 0;
}

