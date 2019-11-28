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
typedef struct Node {
	Data data;
	struct Node *next;
} Node,*PNode;
void readData(vector<Data> &v);
void prime(int s,int &m);
void toHashByPhone(vector<Data> &v,vector<Data> &s);
void searchByPhone(vector<Data> &s,string phone);
void toHashByName(vector<Data> &v,vector<PNode> &f);
int main() {
	vector<Data> v,s;
	vector<PNode> f;
	string phone;
	readData(v);
//	toHashByPhone(v,s);
	toHashByName(v,f);
//	cout<<"输入需要查询的号码："<<endl;
//	getline(cin,phone);
//	searchByPhone(s,phone);
	return 0;
};

void toHashByPhone(vector<Data> &v,vector<Data> &s) {
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
		s[pos]=data;
	}
	for(auto &i:s) {
		cout<<i.name<<" "<<i.phone<<" "<<i.site<<endl;
	}
}

void toHashByName(vector<Data> &v,vector<PNode> &f) {
	int b=v.size(),m=0;
	char *a1,*b1;
	a1=(char *)malloc(sizeof(char));
	b1=(char *)malloc(sizeof(char));
	prime(b,m);
	f.reserve(m+1);
	for(int i=0; i<m+1; ++i) {
		PNode temp=NULL;
		f.push_back(temp);
	}
	for(auto &data:v) {
		int w=data.name.size();
		string b=data.name.substr(1,1);
		string a=data.name.substr(0,1);
		strcpy(a1,a.c_str());
		strcpy(b1,b.c_str());
		int num=(int)a1[0]+(int)b1[0];
		int pos=num%m;
		PNode pdata=f[pos],q=NULL;
		PNode t=(PNode)malloc(sizeof(Node));
		t->data=data;
		t->next=NULL;
		if(pdata!=NULL) {
			if(pdata->next) {
				t->next=pdata->next;
				pdata->next=t;
			} else {
				pdata->next=t;
			}
		} else {
			pdata=t;
		}
		free(t);
	}
	free(a1);
	free(b1);
	PNode r=NULL;
	for(auto &i:f) {
		r=i;
		while(r) {
			cout<<"姓名："<<r->data.name<<" 号码："<<r->data.phone<<" 地址："<<r->data.site<<endl;
			r=r->next;
		}
	}
}

void searchByPhone(vector<Data> &s,string phone) {
	if(phone.size()&&phone.find(" ")!=-1) {
		cout<<"输入的号码不符合要求 over"<<endl;
		return;
	}
	int m=s.size()-1;
	string num=phone.substr(9,2);
	int n=atoi(num.c_str());
	int pos=n%m;
	while(s[pos].phone!=phone) {
		pos++;
		if(pos==m+1) {
			pos=1;
		}
	}
	cout<<"姓名："<<s[pos].name<<"手机号码："<<s[pos].phone<<"	地址:  "<<s[pos].site<<endl;

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

void readData(vector<Data> &v) {
	ifstream infile("E:\\dev\\lab5\\data.txt");
	if(!infile.is_open()) {
		cout<<"文件打开失败"<<endl;
	}
	string str;
	Data data;
	while(getline(infile,str)) {
		int pos1=str.find_first_of(" ",0);
		int pos2=str.find_first_of(" ",pos1+1);
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



