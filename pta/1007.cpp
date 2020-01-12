#include<iostream>
#include<cmath>
using namespace std;
bool primer(int n);
int main() {
	int n,total=0;
	cin>>n;
	int i=0;
	int j=2;
	int a=-1,b=-1;
	while(j<=n) {
		bool k=primer(j);
		if(k) {
			if(i%2==0) {
				a=j;
				if(a-b==2) {
					++total;
				}
			} else {
				b=j;
				if(b-a==2) {
					++total;
				}
			}
			++i;
		}
		++j;
	}
	cout<<total<<endl;
	return 0;
}

bool primer(int n) {
	int flag=1;
	for(int i=2; i<=sqrt(n); ++i) {
		if(n%i==0) {
			flag=0;
			break;
		}
	}
	return flag;
}
