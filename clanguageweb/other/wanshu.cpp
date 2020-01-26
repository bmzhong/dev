#include<iostream>
#include<vector>
using namespace std;
inline void factors(int n);
int main() {
	int n;
	cin>>n;
	for(int i=2; i<=n; ++i) {
		factors(i);
	}
	return 0;
}

inline void factors(int n) {
	vector<int> v;
	for(int i=1; i<=n/2; ++i) {
		if(n%i==0) {
			v.push_back(i);
		}
	}
	int sum=0;
	for(auto it:v){
		sum+=it;
	}
	if(sum==n){
		cout<<n<<" its factors are ";
		int len=v.size();
		for(int i=0;i<len-1;++i){
			cout<<v[i]<<" ";
		}
		cout<<v[len-1]<<endl;
	}
}
