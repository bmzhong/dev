#include<iostream>
#include<vector>
using namespace std;
int main(){
	long long a,b,d;
	cin>>a>>b>>d;
	long long r=a+b;
	vector<long long> v;
	while(r!=0){
		long long k=r%d;
		v.push_back(k);
		r=r/d;
	}
	for(int i=v.size()-1;i>=0;--i){
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
