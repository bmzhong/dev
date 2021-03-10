#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
	int sch;
	int scorce;
}Info,*PInfo;
int main(){
	int n;
	cin>>n;
	vector<Info> v;
	for(int i=0;i<n;++i){
		Info p;
		cin>>p.sch>>p.scorce;
		v.push_back(p);
	}
	
}
