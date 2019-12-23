#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
bool cmp(string v1,string v2);
int main() {
	int n;
	vector<string> v;
	cin>>n;
	stringstream st;
	getchar();
	string str;
	for(int i=0; i<n; ++i) {
		getline(cin,str);
		v.push_back(str);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto &it:v) {
		cout<<it<<endl;
	}
	return 0;
}

bool cmp(string v1,string v2) {
	if(v1.length()!=v2.length()) {
		return v1.length()<v2.length();
	} else {
		return v1<v2;
	}

}
