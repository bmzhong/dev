#include<iostream>
using namespace std;
void ques(int &n,int &total);
int main() {
	int total=0;
	int n;
	cin>>n;
	ques(n,total);
	cout<<total<<endl;
	return 0;
}

void ques(int &n,int &total) {
	if(n==1) {
		return;
	} else {
		if(n%2==0) {
			n=n/2;
			++total;
		} else {
			n=3*n+1;
			n=n/2;
			++total;
		}
		ques(n,total);
	}
}
