#include<iostream>
#include<string>
#include<iterator>
using namespace std;
void integer(string &str);
void decimal(string &str);
void percent(string &str);
void fraction(string &str);
inline void handleDecimal(string &str);
int main() {
	string str;
	getline(cin,str);
	if(str.find("/")!=string::npos) {
		fraction(str);
	} else if(str.find("%")!=string::npos) {
		percent(str);
	} else if(str.find(".")!=string::npos) {
		decimal(str);
	} else {
		integer(str);
	}
	cout<<str<<endl;
	return 0;
}

void integer(string &str) {
	int len=str.length();
	string tstr=str;
	for(int i=0; i<len; ++i) {
		tstr[i]=str[len-i-1];
	}
	while(tstr.size()!=1) {
		string::iterator it=tstr.begin();
		if(tstr[0]=='0') {
			tstr.erase(it);
		} else {
			break;
		}
	}
	str=tstr;
}

void decimal(string &str) {
	string tstr=str;
	int j=tstr.find(".");
	string inte=tstr.substr(0,j);
	string deci=tstr.substr(j+1);
	integer(inte);
	handleDecimal(deci);
	str=inte+"."+deci;
}

inline void handleDecimal(string &str) {
	while(str.size()!=1) {
		string::iterator it=str.begin();
		if(str[0]=='0') {
			str.erase(it);
		} else {
			break;
		}
	}
	int len=str.size();
	string tstr=str;
	for(int i=0; i<len; ++i) {
		tstr[i]=str[len-i-1];
	}
	str=tstr;
}

void percent(string &str) {
	string tstr=str.substr(0,str.size()-1);
	integer(tstr);
	str=tstr+"%";
}

void fraction(string &str) {
	string tstr=str;
	int pos=tstr.find("/");
	string z=tstr.substr(0,pos);
	string m=tstr.substr(pos+1);
	integer(m);
	integer(z);
	tstr=z+"/"+m;
	str=tstr;
}
