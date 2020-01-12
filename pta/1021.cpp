#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string n;
	getline(cin,n);
	map<char,int> m;
	for(int i=0;i<n.size();++i){
		m[n[i]]++;
	}
	for(auto &it:m) {
		cout<<it.first<<":"<<it.second<<endl;
	}
	return 0;
}

