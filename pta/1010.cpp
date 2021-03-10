#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
struct P {
	int coe;
	int exp;
};
int main() {
	int a;
	P p;
	vector<P> v;
	int j=0;
	while(cin>>a) {
		if(j==0) {
			p.coe=a;
			j=1;
			continue;
		} else {
			p.exp=a;
			j=0;
			v.push_back(p);
		}
		if(cin.get()=='\n') {
			break;
		}
	}
	for(int i=0; i<v.size(); ++i) {
		v[i].coe=v[i].coe*v[i].exp;
		v[i].exp=v[i].exp-1;
		if(v[i].coe==0) {
			v.erase(v.begin()+i);
		}
	}
	if(v.size()>0) {
		for(int i=0; i<v.size()-1;++i){
			cout<<v[i].coe<<" "<<v[i].exp<<" ";
		}
		cout<<v.rbegin()->coe<<" "<<v.rbegin()->exp<<endl;
	}else{
		cout<<0<<" "<<0<<endl; 
	}
	
	return 0;
}
