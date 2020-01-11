#include<iostream>
#include<vector>
#include<map> 
#include<algorithm>
using namespace std;
int main(){
	vector<string> v;
	int n;
	string str;
	char c;
	cin>>n;
	cin.get(c);
	for(int i=0;i<n;++i){
		getline(cin,str);
		v.push_back(str);
	}
	map<char,int> m[100];
	for(int i=0;i<v.size();++i){
		for(int j=0;j<v[i].size();++j){
			
		}
	}
	
}
