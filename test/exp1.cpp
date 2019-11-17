#include<iostream>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	int r;
	double x=a,y=1;
	while(b!=0) {
		r=b%2;
		b=b/2;
		if(r==1){
			y=y*x;
		}
		x=x*x;
	}
	cout<<y<<endl;
	return 0;

}
