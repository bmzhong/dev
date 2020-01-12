#include<algorithm>
#include<string> 
#include<iostream>
using namespace std;
int main(){
	string str;
	string str2;
	str="123456789";
	str2="456";
	cout<<find(str.begin(),str.end(),str2);
	return 0;
}
