#include<iostream>
#include<vector>
#include<cstdlib>
#include<typeinfo>
using namespace std;
int main(){
	vector<int> s{1,2,3,4,5,96};
	signed int i=0;
	for(auto &it:s){
		it=212313;
	} 
	s[2]=444;
	for(auto &it:s){
		cout<<it<<" ";
	} 
	return 0; 
}
