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
void searchByName(vector<PNode> &f,string name,int e);
int main() {
	vector<Data> v,s;
	vector<PNode> f;
	string phone;
	cout<<"�ļ��е����ݣ�"<<endl;
	readData(v);
	toHashByPhone(v,s);
	toHashByName(v,f);
	cout<<endl<<"������Ҫ��ѯ�ĺ��룺"<<endl;
	getline(cin,phone);
	searchByPhone(v,phone);
	cout<<endl<<"������Ҫ��ѯ��������"<<endl;
	getline(cin,phone);
	searchByName(f,phone,v.size());
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
//    for(auto &i:s) {
//        cout<<i.name<<" "<<i.phone<<" "<<i.site<<endl;
//    }
}

void toHashByName(vector<Data> &v,vector<PNode> &f) {
	int b=v.size(),m=0;
	char *a1,*b1;
	a1=(char *)malloc(2*sizeof(char));
	b1=(char *)malloc(2*sizeof(char));
	prime(b,m);
	f.reserve(m+1);
	PNode t=new Node;
	for(int i=0; i<m+1; ++i) {
		PNode temp=NULL;
		f.push_back(temp);
	}
	for(auto &data:v) {
		int w=data.name.length();
		string b=data.name.substr(w-2, 1);
		string a=data.name.substr(w-1, 1);
		strcpy(a1,a.c_str());
		strcpy(b1,b.c_str());
		int num=(int)a1[0]+(int)b1[0];
		int pos=num%m;
		if(f[pos]!=NULL) {
			if(f[pos]->next) {
				PNode t=new Node;
				t->data=data;
				t->next=f[pos]->next;
				f[pos]->next=t;
			} else {
				PNode t=new Node;
				t->data=data;
				t->next=NULL;
				f[pos]->next=t;
			}
		} else {
			f[pos]=new Node;
			f[pos]->data=data;
			f[pos]->next=NULL;
		}
	}
	free(a1);
	free(b1);
//    PNode r=NULL;
//    for(auto &i:f) {
//        r=i;
//        while(r) {
//            cout<<"������"<<r->data.name<<" ���룺"<<r->data.phone<<" ��ַ��"<<r->data.site<<endl;
//            r=r->next;
//        }
//    }
}

void searchByName(vector<PNode> &f,string name,int e) {
	int m=0;
	prime(e,m);
	char *a1,*b1;
	a1=(char *)malloc(2*sizeof(char));
	b1=(char *)malloc(2*sizeof(char));
	int w=name.length();
	string b=name.substr(w-2, 1);
	string a=name.substr(w-1, 1);
	strcpy(a1,a.c_str());
	strcpy(b1,b.c_str());
	int num=(int)a1[0]+(int)b1[0];
	int pos=num%m;
	PNode p=f[pos];
	while(p&&p->data.name!=name) {
		p=p->next;
	}
	if(p&&p->data.name==name) {
		cout<<"������"<<p->data.name<<"  �ֻ����룺"<<p->data.phone<<"	��ַ:  "<<p->data.site<<endl;
	} else {
		cout<<"û�д��˻�����������,over"<<endl;
		return;
	}
}

void searchByPhone(vector<Data> &s,string phone) {
	if(phone.size()!=11&&phone.find(" ")!=-1) {
		cout<<"����ĺ��벻����Ҫ�� over"<<endl;
		return;
	}
	int m=s.size()-1;
	string num=phone.substr(9,2);
	int n=atoi(num.c_str());
	int pos=n%m;
	int i=0;
	while(s[pos].phone!=phone) {
		pos++;
		if(pos==m+1) {
			pos=1;
			i++;
		}
		if(i==2) {
			break;
		}
	}
	if(i!=2) {
		cout<<"������"<<s[pos].name<<" �ֻ����룺"<<s[pos].phone<<"	��ַ:  "<<s[pos].site<<endl;
	}else{
		cout<<"û��������������������"<<endl;
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

void readData(vector<Data> &v) {
	ifstream infile("E:\\dev\\lab5\\data.txt");
	if(!infile.is_open()) {
		cout<<"�ļ���ʧ��"<<endl;
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
	for(auto &i:v) {
		cout<<i.name<<" "<<i.phone<<" "<<i.site<<endl;
	}
}
