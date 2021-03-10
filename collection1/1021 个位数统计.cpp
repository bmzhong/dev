#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v,w;
	int n;
	cin>>n;
	int m=n;
	while(m!=0){
		int a=m%10;
		v.push_back(a);
		m=m/10;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		w.push_back(0);
	}
	int i=0;
	while(i<v.size()-1){
		if(v[i]==v[i+1]){
			w[i]++;
			++i;
		}else{
			w[i]=1;
			++i;
		}
	}
	for(int i=v.size()-1;i>=0;++i){
		for(int j=0;j<i;++j){
			if(v[j]>v[j+1]){
				int t=v[j];
				v[j]=v[i];
				v[i]=v[j];
				t=w[j];
				w[j]=w[i];
				w[i]=t;
			}
		}
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<":"<<w[i]<<endl;
	}
	return 0;
}
