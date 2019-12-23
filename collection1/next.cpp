#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
void tonext(string str,int next[]);
int main() {
	string str;
	vector<int> v;
	getline(cin,str);
	int next[100];
	tonext(str,next);
	return 0;
}

void tonext(string str,int next[]) {
	int i=1,j=0;
	next[1]=0;
	while(i<str.length()) {
		if(j==0||str[i]==str[j]) {
			++i;
			++j;
			next[i]=j;
		} else {
			j=next[j];
		}
	}
	for(int i=1;i<str.length()+1;++i) {
		cout<<next[i]<<" ";
	}
	cout<<endl;
}
