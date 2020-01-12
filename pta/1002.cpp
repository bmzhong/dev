#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
int main() {
	string str;
	getline(cin,str);
	stringstream s;
	int sum=0;
	for(int i=0; i<str.size(); ++i) {
		int a;
		s<<str[i];
		s>>a;
		s.clear();
		sum+=a;
	}
	map<char,string> m= {{'0',"ling"},{'1',"yi"},{'2',"er"},{'3',"san"},{'4',"si"},{'5',"wu"},{'6',"liu"}
		,{'7',"qi"},{'8',"ba"},{'9',"jiu"}
	};
	s<<sum;
	s>>str;
	s.clear();
	for(int i=0; i<str.size(); ++i) {
		if(i==str.size()-1) {
			cout<<m[str[i]]<<endl;
		} else {
			cout<<m[str[i]]<<" ";
		}

	}
	return 0;
}
