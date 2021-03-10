#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctype.h>
#include<iterator>
using namespace std;
int main() {
	vector<string> v;
	string str;
	getline(cin,str);
	while(str!="!") {
		v.push_back(str);
		getline(cin,str);
	}
	for(auto &it:v) {
		for(int i=0; i<it.size(); ++i) {
			if(isalpha(it[i])) {
				if(it[i]>='A'&&it[i]<='Z') {
					int dis=it[i]-'A';
					it[i]='Z'-dis;
				} else {
					int dis=it[i]-'a';
					it[i]='z'-dis;
				}
			}
		}
	}
	for(auto &it:v){
		cout<<it<<endl;
	}
	system("pause");
	return 0;
}


