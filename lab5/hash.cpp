#include<iostream>
#include<cstdlib>
#include<vector>
#include<iterator>
#include<string>
#include<string.h>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;
typedef struct Data {
	string name;
	string phone;
	string site;
} Data,*PData;
void readData(vector<Data> &v);
void prime(int s,int &m);
void toHash(vector<Data> &v,vector<Data> &s);
int main() {
	vector<Data> v,s;
	readData(v);
	toHash(v,s);
	return 0;
};
void readData(vector<Data> &v) {
	ifstream infile("E:\\dev\\lab5\\data.txt");
	if(!infile.is_open()) {
		cout<<"文件打开失败"<<endl;
	}
	string str;
	Data data;
	while(getline(infile,str)) {
		int pos1=str.find_first_of(" ",0);
		int pos2=str.find_first_of(" ",pos1);
		data.name=str.substr(0,pos1);
		data.phone=str.substr(pos1+1,11);
		int len=str.length()-data.name.length()-data.phone.length()-2;
		data.site=str.substr(pos2+1,len);
		v.push_back(data);
	}
//	for(auto &i:v) {
//		cout<<i.name<<" "<<i.phone<<" "<<i.site<<endl;
//	}
}

void toHash(vector<Data> &v,vector<Data> &s) {
	Data temp;
	temp.name="null";
	temp.phone="null";
	temp.site="null";
	int b=v.size(),m=0;
	prime(b,m);
	s.reserve(m+1);
	for(int i=0; i<m+1; ++i) {
		s.push_back(temp);
	}
	for(auto &data:v) {
		string n=data.phone.substr(9,2);
		int num=atoi(n.c_str());
		int pos=num%m;
		while(s[pos].name!="null") {
			pos++;
			if(pos==m+1) {
				pos=0;
			}
		}
		replace(begin(s),begin(s),s[pos],v[1]);
	}
	for(auto &i:s) {
		cout<<i.name<<" "<<i.phone<<" "<<i.site<<endl;
	}
}

void prime(int s,int &m) {
	m=0;
	for(int i=s;; ++i) {
		for(int j=2; j<=(int)sqrt(i); ++j) {
			if(i%j==0) {
				break;
			} else if(j==(int)sqrt(i)) {
				m=i;
			}
		}
		if(m!=0) {
			break;
		}
	}
}




