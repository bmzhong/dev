#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	vector<int> v;
	for(int i=0; i<n; ++i) {
		int a;
		cin>>a;
		v.push_back(a);
	}
	vector<int> k(v.size());
	cout<<"k的大小		"<<k.size()<<endl;
	copy(v.begin(),v.end()-m,k.begin());
	int a=v.size();
	for(int i=1; i<=m; ++i) {
		k.insert(k.begin(),v[a-i]);
	}
	int b=v.size();
	cout<<"k的大小		"<<k.size()<<endl;
	for(int i=0; i<b; ++i) {
		if(i!=b-1) {
			cout<<k[i]<<" ";
		} else {
			cout<<k[i]<<endl;
		}
	}
	return 0;
}
