#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main() {
	int n=33333;
	string  str;
	stringstream st;
	st<<n;
	st>>str;
	cout<<str<<endl;
	st.clear();
	string str1="hello";
	char c[20];
	st<<str1;
	st>>c;
	cout<<c<<endl;
	st.clear();
	int s=6665555;
	st<<s;
	string str2;
	st>>str2;
	cout<<str2<<endl;
	string str3="ello";
	string str4="fdasfdas";
	str3.insert(0,str4);
	cout<<str3<<endl;
	return 0;
}
