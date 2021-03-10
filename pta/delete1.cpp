#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<random>
using namespace std;
struct P {
	int a=0;
	double b=0.0;
	string str="";
};

bool cmp(P &c,P &d){
	return c.a>d.a;
}

bool operator < (P &c,P &d) {
	if(c.a<d.a){
		return true;
	}else if(c.a==d.a){
		if(c.b<d.b){
			return true;
		}else if(c.b==d.b){
			return c.str<d.str;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main() {
	vector<P> v;
	for(int i=0; i<10; ++i) {
		string str1;
		str1.assign(i,char(i+int('a')));
		P p;
		p.a=rand()%4;
		p.b=rand()%6;
		p.str=str1;
		v.push_back(p);
	}
	random_shuffle(v.begin(),v.end());
	sort(v.begin(),v.end(),cmp);
	for(auto it:v) {
		cout<<it.a<<" "<<it.b<<" "<<it.str<<endl;
	}
	return 0;
}
