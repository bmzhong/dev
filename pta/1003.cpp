#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool j1(string str);
bool j2(string str);
bool j3(string str);
bool j4(string str);
int main() {
	int n;
	string str="AAAsPATAAAA";
	vector<string> v;
	vector<string> m;
	cin>>n;
	char c;
	cin.get(c);
	for(int i=0; i<n; ++i) {
		getline(cin,str);
		v.push_back(str);
	}
	for(auto it:v){
		if(j1(it)||(j2(it))||j3(it)||j4(it)){
			cout<<"YES"<<endl; 
		}else{
			cout<<"NO"<<endl;
		}
	}
}

bool j1(string str) {
	int pos;
	if(str=="PAT") {
		return true;
	}
	if(pos=str.find("PAT")!=string::npos) {
		if((str.size()-3)>0&&(str.size()-3)%2==0&&pos!=0&&pos<str.size()-3) {
			string str1,str2,str3;
			str1=str.substr(0,pos);
			str2=str.substr(pos+3);
			str3.assign(pos,'A');
			if(str1==str2&&str1==str3) {
				return true;
			}
		}
	}
	return false;
}

bool j2(string str) {
	if(str=="PAT"||str=="APATA") {
		return true;
	}
	return false;
}

bool j3(string str) {
	if(str[0]=='P'||str[str.size()-1]=='T') {
		string str1=str.substr(1,str.size()-2);
		string str2;
		str2.assign(str.size()-2,'A');
		if(str1==str2) {
			return true;
		}
	}
	return false;
}

bool j4(string str) {
	int a=str.find('T');
	if(str[0]=='A'&&str[1]=='P'&&a!=string::npos&&a!=str.size()-1) {
		string str1=str.substr(2,a-2);
		string str2=str.substr(a+1,str.size()-(a+1));
		string str3;
		str3.assign(a-2,'A');
		if(str1==str2&&str1==str3) {
			return true;
		}
	}
	return false;
}
