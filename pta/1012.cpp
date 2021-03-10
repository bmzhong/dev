#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; ++i) {
		int a;
		cin>>a;
		v.push_back(a);
	}
	int a1=0;
	for(auto it:v) {
		if(it%5==0&&it%2==0) {
			a1+=it;
		}
	}
	if(a1==0) {
		cout<<'N'<<" ";
	} else {
		cout<<a1<<" ";
	}
	int j=0;
	int a2=0;
	for(auto it:v) {
		if(it%5==1) {
			if(j%2==0) {
				a2+=it;
			} else {
				a2-=it;
			}
			++j;
		}
	}
	if(a2==0) {
		cout<<'N'<<" ";
	} else {
		cout<<a2<<" ";
	}
	int a3=0;
	for(auto it:v) {
		if(it%5==2) {
			++a3;
		}
	}
	if(a3==0) {
		cout<<'N'<<" ";
	} else {
		cout<<a3<<" ";
	}
	double a4=0;
	int k=0;
	for(auto it:v) {
		if(it%5==3) {
			++k;
			a4+=it;
		}
	}
	a4=(double)(a4/j);
	if(a4==0) {
		cout<<'N'<<" ";
	} else {
		cout<<fixed<<setprecision(1)<<a4<<" ";
	}

	int a5=0;
	for(auto it:v) {
		if(it%5==4) {
			if(it>a5) {
				a5=it;
			}
		}
	}
	if(a5==0) {
		cout<<'N'<<" ";
	} else {
		cout<<a5<<endl;
	}
	return 0;
}
