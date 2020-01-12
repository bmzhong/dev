#include<iostream>
#include<cmath>
using namespace std;
bool isprimer(int n);
int main() {
	int n,m;
	cin>>n>>m;
	int i=2;
	int j=0;
	int p=0;
	while(true) {
		bool k=isprimer(i);
		if(k==true) {
			++j;
			if(j>m) {
				break;
			}
			if(j>=n) {
				++p;
				if(p<=9&&j<m) {
					cout<<i<<" ";
				} else {
					p=0;
					cout<<i<<endl;
				}
			}

		}
		++i;
	}
	return 0;
}
bool isprimer(int n) {
	int flag=1;
	for(int i=2; i<=sqrt(n); ++i) {
		if(n%i==0) {
			flag=0;
			break;
		}
	}
	return flag;
}
