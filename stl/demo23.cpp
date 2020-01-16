#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1();
    string s2("hello");
    string s3(4,'k');
    string s4("1234",1,3);
    string s5,s6,s7;
    s5="hello";
    s6='k';
    s7.assign(s2);
    s7.assign(s2,1,2);
    s7.assign(4,'k');
    s7.assign("abcdef",2,3);
    int len=s2.length();
    s2.append(s3);
    s2.append(s3,1,2);
    s2.append(3,'k');
    s2.append("ABCDE",2,3);
    string str1("hello"),str2("hello world");
    int n=str1.compare(s2);
    n=str1.compare(1,2,s2,0,3);
    n=str1.compare(0,2,str2);
    n=str1.compare("Hello");
    n=str1.compare(1,2,"Hello");
    n=str1.compare(1,2,"Hello",1,2);
    string ss1="this is ok";
    string ss2=ss1.substr(2,4);
    ss2.substr(2);
    ss1.swap(ss2);
    ss1.replace(1,3,"123456",2,4);
    ss1.replace(2,3,5,'0');
    ss1.replace(1,5,"xxx");
    ss1="real steel";
    ss1.erase(1,3);
    ss1.erase(5);//删除下标5及以后所有字符。
    ss1="limitless";
    ss2="00";
    ss1.insert(2,"123");
    ss1.insert(3,s2);
    ss1.insert(3,5,'x');
    string s="abcdefgh";
    string::iterator p=find(s.begin(),s.end(),'c');
    if(p!=s.end()){
        cout<<p-s.begin()<<endl;
    }
    sort(s.begin(),s.end());
    next_permutation(s.begin(),s.end());
    cout<<s<<endl;
    system("pause");
    return 0;
}