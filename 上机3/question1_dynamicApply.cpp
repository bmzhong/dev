#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef struct {
	char *ch;
	int length;
} String;
Status strAssign(String &s,char *ch);
Status print(String s);
int main() {
	char *ch;
	ch=(char*)malloc(200*sizeof(char));
	String s;
	cin.getline(ch,200);
	strAssign(s,ch);
	print(s);
	return 0;
}
Status strAssign(String &s,char *ch) {
//	if(s.ch) {
//		free(s.ch);
//	}
	int sum=0;
	while(ch[sum]!='\0') {
		sum++;
	}
	if(sum==0) {
		s.ch=NULL;
		s.length=0;
	} else {
		s.ch=(char *)malloc(sizeof(char)*sum);
		if(!s.ch) {
			exit(OVERFLOW);
		}
		s.length=sum;
		for(int i=0; i<sum; ++i) {
			s.ch[i]=ch[i];
		}
	}
	return OK;
}

Status print(String s) {
	for(int i=0; i<s.length; ++i) {
		cout<<s.ch[i];
	}
	cout<<endl;
	return OK;
}

int getLength(String s){
	return s.length; 
}
