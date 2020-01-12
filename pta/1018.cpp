#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int judge(char c1,char c2);
struct Info {
	int v;
	int p;
	int d;
};
void printf1(map<char,Info> &m1 );
void printf2(map<char,Info> &m1);
bool operator < (Info &a,Info &b) {
	return a.v<a.v;
}
int main() {
	map<char,Info> m1;
	map<char,Info> m2;
	int n;
	cin>>n;
	char c1,c2;
	for(int i=0; i<n; ++i) {
		cin>>c1>>c2;
		int a=judge(c1,c2);
		if(a>0) {
			m1[c1].v++;
			m2[c2].d++;
		} else if(a==0) {
			m1[c1].p++;
			m2[c2].p++;
		} else {
			m1[c1].d++;
			m2[c2].v++;
		}
	}
	printf1(m1);
	printf1(m2);
	printf2(m1);
	cout<<" ";
	printf2(m2);
	cout<<endl;
	return 0;
}

void printf2(map<char,Info> &m1) {
	char c='B';
	int t=m1['B'].v;
	if(m1['C'].v>t) {
		c='C';
		t=m1['C'].v;
	}
	if(m1['J'].v>t) {
		c='J';
	}
	cout<<c;
}

void printf1(map<char,Info> &m1 ) {
	cout<<m1['C'].v+m1['J'].v+m1['B'].v<<" ";
	cout<<m1['C'].p+m1['J'].p+m1['B'].p<<" ";
	cout<<m1['C'].d+m1['J'].d+m1['B'].d<<endl;
}

int judge(char c1,char c2) {
	if(c1==c2) {
		return 0;
	} else {
		if((c1=='C'&&c2=='J')||(c1=='J'&&c2=='B')||(c1=='B'&&c2=='C')) {
			return 1;
		} else {
			return -1;
		}
	}
}
