#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>
#include<random>
#include<ctime>
#include<string>
#include<string.h>
#include<windows.h>
using namespace std;
void write();
void read(vector<int> &b);
void partition(vector<int> &v,int low,int high,int &pivotloc,int &sw,int &move,int &compare);
void select(vector<int> &s);
void bubble(vector<int> &b);
void quickSort(vector<int> &v,int low,int high,int &sw,int &move,int &compare);
void insert(vector<int> &in);
int main() {
	int sw=0,move=0,compare=0;
	vector<int> v;
	write();
	read(v);
	v.insert(v.begin(),0);
	DWORD start1,end1;
	start1=GetTickCount();
	quickSort(v,1,v.size()-1,sw,move,compare);
	end1=GetTickCount();
	cout<<"时间："<<(end1-start1)/55<<"ms  "<<endl;
	cout<<"是否有序："<<(is_sorted(v.begin()+1,v.end())?"是":"否")<<endl;
		cout<<"交换次数："<<sw<<"	比较次数："<<compare<<"    移动次数："<<move<<endl;
//	vector<int> s(b.begin(),b.end());
//	vector<int> in(b.begin(),b.end());
//	DWORD start1,end1,start2,end2,start3,end3;
//	start1=GetTickCount();
//	bubble(b);
//	end1=GetTickCount();
//	cout<<"时间："<<(end1-start1)/55<<"ms  "<<endl<<endl;
//	start2=GetTickCount();
//	select(b);
//	end2=GetTickCount();
//	cout<<"时间："<<(end2-start2)/55<<"ms  "<<endl<<endl;
//	start3=GetTickCount();
//	insert(in);
//	end3=GetTickCount();
//	cout<<"时间："<<(end3-start3)/55<<"ms  "<<endl<<endl;
	return 0;
}

void quickSort(vector<int> &v,int low,int high,int &sw,int &move,int &compare) {
	int pivotloc=0;
	if(low<high) {
		compare++;
		partition(v,low,high,pivotloc,sw,move,compare);
		quickSort(v,low,pivotloc-1,sw,move,compare);
		quickSort(v,pivotloc+1,high,sw,move,compare);
	}
}

void partition(vector<int> &v,int low,int high,int &pivotloc,int &sw,int &move,int &compare) {
	v.front()=v[low];
	move++;
	int pivotkey=v[low];
	while(low<high) {
		compare++;
		while(low<high&&v[high]>=pivotkey) {
			--high;
			compare+=2;
		}
		v[low]=v[high];
		move++;
		while(low<high&&v[low]<=pivotkey) {
			++low;
			compare+=2;
		}
		v[high]=v[low];
		move++;
	}
	v[low]=v.front();
	move++;
	pivotloc=low;
}

void write() {
	srand((unsigned int)time(NULL));
	ofstream outfile("E:\\dev\\lab6\\intfile.txt");
	if(!outfile.is_open()) {
		cout<<"文件打开失败 over"<<endl;
	}
	int t=0;
	for(int i=1; i<=1000000; ++i) {
		t=rand()%10000;
		outfile<<t<<"\t";
		if(i%10==0) {
			outfile<<"\n";
		}
	}
}
void read(vector<int> &b) {
	ifstream infile("E:\\dev\\lab6\\intfile.txt");
	if(!infile.is_open()) {
		cout<<"文件打开失败 over"<<endl;
	}
	string str;
	char *c=(char *)malloc(100*sizeof(char));
	char *r=(char *)malloc(100*sizeof(char));
	const char *t;
	while(getline(infile,str)) {
		strcpy(c,str.c_str());
		r=strtok(c,"	");
		while(r!=NULL) {
			const char *t=r;
			int num=atoi(t);
			b.push_back(num);
			r=strtok(NULL,"	");
		}
	}
}
//
//void bubble(vector<int> &b) {
//	int sw=0,move=0,compare=0;
//	for(int i=b.size()-1; i>=0; --i) {
//		compare++;
//		for(int j=0; j<i; ++j) {
//			compare++;
//			if(b[j]>b[j+1]) {
//				swap(b[j],b[j+1]);
//				sw++;
//			}
//			compare++;
//		}
//	}
//	cout<<"冒泡法："<<endl;
//	cout<<"是否有序："<<(is_sorted(b.begin(),b.end())?"是":"否")<<endl;
//	cout<<"交换次数："<<sw<<"	比较次数："<<compare<<"    移动次数："<<move<<endl;
//
//}
//
//void select(vector<int> &s) {
//	int sw=0,move=0,compare=0;
//	for(int i=s.size()-1; i>=0; --i) {
//		compare++;
//		for(int j=0; j<i; ++j) {
//			compare++;
//			if(s[i]<s[j]) {
//				swap(s[i],s[j]);
//				sw++;
//			}
//			compare++;
//		}
//	}
//	cout<<"选择法："<<endl;
//	cout<<"是否有序："<<(is_sorted(s.begin(),s.end())?"是":"否")<<endl;
//	cout<<"交换次数："<<sw<<"	比较次数："<<compare<<"    移动次数："<<move<<endl;
//}
//
//void insert(vector<int> &in) {
//	int sw=0,move=0,compare=0;
//	in.insert(in.begin(),0);
//	int t,i,j;
//	for(i=2; i<=in.size(); ++i) {
//		compare++;
//		in.front()=in[i];
//		move++;
//		t=in[i];
//		for(j=i-1; in.front()<in[j]; --j) {
//			compare++;
//			in[j+1]=in[j];
//			move++;
//		}
//		in[j]=in.front();
//	}
//	cout<<"直接插入法："<<endl;
//	cout<<"是否有序："<<(is_sorted(in.begin(),in.end())?"是":"否")<<endl;
//	cout<<"交换次数："<<sw<<"	比较次数："<<compare<<"    移动次数："<<move<<endl;
//}


