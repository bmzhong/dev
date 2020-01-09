#include<iostream>
#include<windows.h>
using namespace std;
int adbin(int x,int k) ;
int bi(int x,int k);
int main() {
	DWORD s1,e1,s2,e2;
	s1=GetTickCount();
	int r1=adbin(2,30);
	for(int i=0; i<100000000; i++) {

	}
	e1=GetTickCount();
	s2=GetTickCount();
	int r2=bi(2,30);
	e2=GetTickCount();
	int t1=(e1-s1)/55;
	int t2=(e2-s2)/55;
	cout<<r1<<" "<<t1<<endl;
	cout<<r2<<" "<<t2<<endl;
	return 0;
}
int adbin(int x,int k) {
	if(k==1) return x;
	int t=adbin(x,k/2);
	if(k%2==0) return t*t;
	return t*t*x;
}

int bi(int a,int b) {
	int r;
	int x = a;
	int y = 1;
	while(b != 0) {
		r = b % 2;
		b = b / 2;
		if(r == 1)     {
			y *= x;
		}
		x = x * x;
	}
	for(int i=0; i<100000000; i++) {

	}
	return y;
}
