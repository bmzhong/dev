#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> v;
	while(n!=0) {
		int a=n%10;
		v.push_back(a);
		n/=10;
	}
	string s1,s2,s3="";
	s1.assign(v[2],'B');
	s2.assign(v[1],'S');
	for(int i=1;i<=v[0];++i){
		stringstream s;
		char k;
		s<<i;
		s>>k;
		s3=s3+k;
		s.clear();
	} 
	string str;
	str=s1+s2+s3;
	cout<<str<<endl;
	return 0;
}
