#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()

{
	
	string str="fds";
	const string str1="fedasfd";
	bool f=typeid(str1).name()==typeid(str).name();
	cout<<f<<endl;
	
//	string str;
//	getline(cin,str);
//	cout<<str.length();
	return 0; 

}

