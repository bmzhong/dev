#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>
#include<random> 
#include<ctime>
using namespace std;
void write();
int main(){
	write();
	return 0;
}

void write(){
	srand((unsigned int)time(NULL));
 	ofstream outfile("");
 	if(!outfile.is_open()){
 		cout<<"文件打开失败 over"<<endl;
	 }
 	int t=0;
 	for(int i=0;i<10000;++i){
 		t=rand()%1000;
 		outfile<<t<<" ";
 		if(i%20==0){
 			outfile<<"\n";
		 }
	 }
	 
}

