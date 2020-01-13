#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a,b,c;
	vector<bool> v;
	for(int i=0;i<n;++i){
		cin>>a>>b>>c;
		if(c<a+b){
			v.push_back(true);
		}else{
			v.push_back(false);
		}
	} 
	for(int i=0;i<n;++i){
		if(v[i]){
			cout<<"Case #"<<(i+1)<<": true"<<endl; 
		}else{
			cout<<"Case #"<<(i+1)<<": false"<<endl; 
		}
	} 
	return 0;
}
