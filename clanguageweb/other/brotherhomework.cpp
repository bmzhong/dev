#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
void add(string &str,bool &j);
int main() {
	vector<string> v;
	string str;
	while(getline(cin,str)) {
		v.push_back(str);
	}
	bool j;
	int sum=0;
	for(auto &it:v){
		add(it,j);
		if(j==true){
			sum++;
		}
	}
	cout<<sum<<endl;
	
	add()
	return 0;
}

void add(string &str,bool &j) {
	string split;
	if(str.find("+")!=string::npos){
		split="+";
	} else if(str.find("-")!=string::npos){
		split="-";
	}
	j=false;
	int pos=str.find(split);
	int e=str.find("=");
	string p=str.substr(0,pos);
	string s=str.substr(pos+1,e-(pos+1));
	string r=str.substr(e+1);
	if(r=="?") {
		return;
	}
	stringstream sstr;
	int pp,ss,rr;
	sstr<<p;
	sstr>>pp;
	sstr.clear();
	sstr<<s;
	sstr>>ss;
	sstr.clear();
	sstr<<r;
	sstr>>rr;
	sstr.clear();
	if(split=="+") {
		if(pp+ss==rr) {
			j=true;
		} 
	}else if(split=="-"){
		if(pp-ss==rr){
			j=true;
		}
	}
}
//37 是e+1而不是e
//stringstream使用一次后应clear(); 
