#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<string> v;
	string str;
	while(getline(cin,str)){
		sort(str.begin(),str.end());
		v.push_back(str);
	}
	for(auto &it:v){
		cout<<it<<endl;
	}
	return 0;
}
