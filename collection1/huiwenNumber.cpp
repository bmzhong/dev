#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v;
	int m=n;
	while(m!=0){
		int a=m%10;
		v.push_back(a);
		m=m/10;
	}
	int flag=0;
	for(int i=0;i<v.size()/2;++i){
		if(v[i]!=v[v.size()-i-1]){
			flag=1;	
			break;
		}
	}
	int sum=0;
	for(auto it:v){
		sum=it+sum;
	}
	if(flag==0){
		cout<<sum<<endl;
	}else{
		cout<<"no"<<endl;
	}
	return 0;
}
