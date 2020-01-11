#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef struct Info {
	string name;
	string id;
	int score;
} Info,*PInfo;
bool cmp(Info &a,Info &b);
int main() {
	int n;
	cin>>n;
	vector<Info> v;
	for(int i=0; i<n; ++i) {
		Info t;
		cin>>t.name>>t.id>>t.score;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v[v.size()-1].name<<" "<<v[v.size()-1].id<<endl;
	cout<<v[0].name<<" "<<v[0].id<<endl;
	return 0;
}

bool cmp(Info &a,Info &b) {
	return a.score<b.score;
}
