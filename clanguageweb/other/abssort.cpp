#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b);
int main() {
	int n;
	vector<int> v[1000];
	cin>>n;
	int j=0;
	while(n!=0) {
		for(int i=0; i<n; ++i) {
			int a;
			cin>>a;
			v[j].push_back(a);
		}
		cin>>n;
		j++;
	}
	for(int i=0; i<j; ++i) {
		sort(v[i].begin(),v[i].end(),cmp);
		for(int k=0;k<v[i].size();k++){
			cout<<v[i][k];
			if(k==v[i].size()-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
bool cmp(int a,int b) {
	if(abs(a)<abs(b)) {
		return false;
	}
	return true;
}
