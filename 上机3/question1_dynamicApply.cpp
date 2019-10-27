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

int getLength(String s) {
	return s.length;
}

Status strConcat(String &s1,String &s2,String &s) {
	int length=s1.length+s2.length;
	s.ch=(char *)malloc(length*sizeof(char));
	s.length=length;
	if(!s.ch) {
		exit(OVERFLOW);
	}
	int i=0;
	for(i=0; i<(s1.length+s2.length); ++i) {
		if(i<s1.length) {
			s.ch[i]=s1.ch[i];
		} else {
			s.ch[i]=s2.ch[i-s1.length];
		}
	}
	return OK;
}

Status strConcat(String &s1,String &s2) {
	s1.ch=(char *)realloc(s1.ch,(s1.length+s2.length)*sizeof(char));
	for(int i=s1.length; i<(s1.length+s2.length); ++i) {
		s1.ch[i]=s2.ch[i-s1.length];
	}
	s1.length=s1.length+s2.length;
	return OK;
}

Status strSub(String s,String &sub,int i,int len) {
	sub.ch=(char *)malloc(len*sizeof(char));
	if(i>s.length||i<0||len>(s.length-i+1)) {
		return ERROR;
	}
	for(int j=i-1; j<(i+len-1); ++j) {
		sub.ch[j-i+1]=s.ch[j];
	}
	sub.length=len;
	return OK;
}

int strCmp(String s1,String s2) {
	for(int i=0; i<s1.length&&i<s2.length; ++i) {
		if(s1.ch[i]!=s2.ch[i]) {
			return s1.ch[i]-s2.ch[i];
		}
		++i;
	}
	return s1.length-s2.length;
}

int strIndex(String &s,String t,int pos) {
	String temp;
	int i=pos;
	while(i<=(s.length-t.length+1)) {
		strSub(s,temp,i,t.length);
		if(strCmp(temp,t)==0) {
			return i;
		} else {
			++i;
		}
	}
	return 	-1;
}

Status strInsert(String &s,int i,String t) {
	s.ch=(char *)realloc(s.ch,(s.length+t.length)*sizeof(char));
	String sub;
	strSub(s,sub,i,s.length-i+1);
	int j=i;
	for(j=i; j<(i+len); ++j) {
		s.ch[j]=t.ch[j-i];
	}
	for(j; j<(s.length+t.length); ++j) {
		s.ch[j]=sub.ch[j-(i+len)];
	}
	s.length=s.length+t.length;
	return OK;
}
/*
疑问：	if(s.ch) {
		    free(s.ch);
        	}发生错误。定义s后，s.ch为空吗？
*/
