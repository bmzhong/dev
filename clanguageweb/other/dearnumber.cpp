#include<iostream>
#include<vector>
using namespace std;
inline void factors(int n,int &sum);
int main() {
	int sum1,sum2;
	for(int i=2; i<3000; ++i) {
		factors(i,sum1);
		factors(sum1,sum2);
		if(sum2==i&&i<sum1){
			cout<<"("<<i<<","<<sum1<<")";
		}
	}
	return 0;
}

inline void factors(int n,int &sum) {
	vector<int> v;
	for(int j=1; j<=n/2; j++) {
		if(n%j==0) {
			v.push_back(j);	
		}
	}
	sum=0;
	for(auto &it:v){
		sum+=it;
	}
}
