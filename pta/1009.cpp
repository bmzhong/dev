#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
    string str;
    getline(cin,str);
    string str1("");
    int a(0),b(0);
    stack<string> s;
    string str2;
    while((a=str.find(' ',a+1))!=string::npos) {
        if(b==0){
            str2=str.substr(b,a-b);
        }else{
            str2=str.substr(b+1,a-b-1);
        }
        b=a;
        s.push(str2);
    }
    string str3=str.substr(b+1);
    s.push(str3);
    while(!s.empty()) {
        if(s.size()!=1) {
            str1=str1+s.top()+" ";
            s.pop();
        }else{
            str1=str1+s.top();
            s.pop();
        }
    }
    cout<<str1<<endl;
    return 0;
}
