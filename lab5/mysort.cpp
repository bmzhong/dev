#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>
#include<random>
#include<ctime>
#include<string>
#include<string.h>
using namespace std;
void write();
int main() {
	vector<int> v;
	write();
	return 0;
}

void write() {
	srand((unsigned int)time(NULL));
	ofstream outfile("E:\\dev\\lab6\\data.txt");
	if(!outfile.is_open()) {
		cout<<"文件打开失败 over"<<endl;
	}
	int t=0;
	for(int i=1; i<=10000; ++i) {
		t=rand()%1000;
		outfile<<t<<"\t";
		if(i%10==0) {
			outfile<<"\n";
		}
	}
}
void read(vector<int>) {
	ifstream infile("E:\\dev\\lab6\\data.txt");
	if(!infile.is_open()) {
		cout<<"文件打开失败 over"<<endl;
	}
	string str;
	char *c=(char *)malloc(100*sizeof(char));
	char *r=(char *)malloc(100*sizeof(char));
	const char *t;
	while(getline(infile,str)){
		strcpy(c,str.c_str());
		r=strtok(c,"	");
		while(r!=NULL){
			const char *t=r;
			int num=atoi(t);
			r=strtok(NULL,"	");
		}
		
	}
}
