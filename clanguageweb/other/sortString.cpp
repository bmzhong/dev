#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool cmp(string &a,string &b);
int main() {
	vector<string> v[100];
	int n;
	string str;
	char a;
	int j=0;
	while(cin>>n) {
		cin.get(a);
		for(int i=0; i<n; ++i) {
			getline(cin,str);
			if(str=="stop") {
				break;
			}
			v[j].push_back(str);
		}
		++j;
	}
	for(int i=0; i<j; ++i) {
		sort(v[i].begin(),v[i].end(),cmp);
		for(auto &it:v[i]) {
			cout<<it<<endl;
		}
	}
	return  0;
}

bool cmp(string &a,string &b) {
	return a.length()<b.length();
}
