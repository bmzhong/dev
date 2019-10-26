#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
#define MAXSTRLEN 1000
#define OK 1
typedef int Status;
typedef char String[MAXSTRLEN+1];
int strlen(char *str);
Status strAssign(String &str,char *ch);
Status strConcat(String s1,String s2,String &s);
int getLength(String str);
int main() {
	String s1,s2,s;
	char *ch1,*ch2;
	ch1=(char*)malloc(sizeof(char)*50);
	ch2=(char*)malloc(sizeof(char)*50);
	cin.getline(ch1,50);
	cin.getline(ch2,50);
	cout<<"ch1:"<<ch1<<endl;
	cout<<"ch2:"<<ch2<<endl;
	strAssign(s1,ch1);
	strAssign(s2,ch2);
	for(int i=1; i<=(int)s1[0]; ++i) {
		cout<<s1[i];
	}
	cout<<endl;
	for(int i=1; i<=(int)s2[0]; ++i) {
		cout<<s2[i];
	}
	cout<<endl;
	strConcat(s1,s2,s);
	cout<<(int)s[0]<<endl;
	for(int i=1; i<=(int)s[0]; ++i) {
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}

int getLength(String str) {
	return (int)str[0];
}

int strlen(char *str) {
	int i=0;
	while(str[i]!='\0') {
		++i;
	}
	return i;
}

Status strAssign(String &str,char *ch) {
	if(strlen(ch)>MAXSTRLEN) {
		for(int i=1; i<MAXSTRLEN; ++i) {
			str[i]=*(ch+i-1);
		}
		str[0]=(char)MAXSTRLEN;
	} else {
		str[0]=(char)strlen(ch);
		for(int i=1; i<=str[0]; ++i) {
			str[i]=*(ch+i-1);
		}
	}
	return OK;
}

Status strConcat(String s1,String s2,String &s) {
	int length1=getLength(s1);
	int length2=getLength(s2);
	int i=1;
	for(i=1; i<=length1&&i<=MAXSTRLEN; ++i) {
		s[i]=s1[i];
	}
	for(i; i<=(length1+length2)&&i<=MAXSTRLEN; ++i) {
		s[i]=s2[i-length1];
	}
	if(MAXSTRLEN>=(length1+length2)) {
		s[0]=(char)(length1+length2);
	} else if(MAXSTRLEN>length1&&MAXSTRLEN<(length1+length2)) {
		s[0]=(char)MAXSTRLEN;
	} else {
		s[0]=(char)length1;
	}
	return OK;
}
