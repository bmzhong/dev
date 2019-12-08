#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
int main() {
	vector<int> v1;
	int k,a;
	scanf("%d",&k);
	while(1) {
		cin>>a;
		if (a>=0) {
			v1.push_back(a);
		} else {
			break;
		}
	}
	int size=v1.size();
	if(k>size) {
		printf("NULL");
	}
	if(k<(1/2)*v1.size()) {
		printf("%d",*(v1.rbegin()-k+1));
	} else {
		int a=size-k;
		printf("%d",*(v1.begin()+a));
	}
	return 0;
}
