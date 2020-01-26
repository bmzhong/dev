#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;
bool cmp(string &a,string &b) ;
int main() {
	int n;
	cin>>n;
	set<string,int> s;
	 
	char c;
	cin.get(c);
	string str;
	vector<string> v;
	for(int i=0; i<n; ++i) {
		getline(cin,str);
		sort(str.begin(),str.end(),cmp);
		v.push_back(str);
	}
	for(auto &it:v){
		cout<<it<<endl;
	}
	return 0;

}

bool cmp(string &a,string &b) {
//	string s1=a.substr(6,8);
//	string s2=b.substr(6,8);
//	if(s1<s2) {
//		return false;
//	} else {
//		return !(a<b);
//	}
}
