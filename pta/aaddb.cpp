#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main() {
	string str1,str2;
	char a,b;
	cin>>str1>>a>>str2>>b;
	int a1=0,b1=0;
	for(int i=0;i<str1.size();++i){
		if(str1[i]==a){
			a1++;
		}
	}
	for(int i=0;i<str2.size();++i){
		if(str2[i]==b){
			b1++;
		}
	}
	if(a1==0){
		a1=1;
		a='0';
	}
	if(b1==0){
		b1=1;
		b='0';
	}
	string s1,s2;
	s1.assign(a1,a);
	s2.assign(b1,b);
	stringstream s;
	int r1,r2;
	s<<s1;
	s>>r1;
	s.clear();
	s<<s2;
	s>>r2;
	s.clear();
	cout<<r1+r2<<endl;
	return 0;
}
