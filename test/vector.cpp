#include<iostream>
#include<vector>
#include<cstdlib>
#include<typeinfo>
using namespace std;
int main(){
	vector<int> s{1,2,3,4,5,96},v1;
//	signed int i=0;
//	for(auto &it:s){
//		it=212313;
//	} 
//	s[2]=444;
//	for(auto &it:s){
//		cout<<it<<" ";
//	} 
	v1.push_back(0);
	v1.front()=1;
	cout<<v1.front();
	return 0; 
}
