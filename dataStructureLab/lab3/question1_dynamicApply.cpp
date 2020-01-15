#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define INFEASIBLE -2
#define OVERFLOW -1
typedef int Status;
typedef struct {
	char *ch;
	int length;
} String;
Status strAssign(String &s,char *ch);
Status print(String s);
int getLength(String s);
Status strConcat(String &s1,String &s2,String &s);
Status strConcat(String &s1,String &s2);
Status strSub(String s,String &sub,int i,int len);
int strCmp(String s1,String s2);
int strIndex(String &s,String t,int pos);
Status strInsert(String &s,int i,String t);
Status strDelete(String &S,int i,int len);
Status strRep(String &S,String t,String r);
int main() {
	char *ch1,*ch2;
	ch1=(char*)malloc(200*sizeof(char));
	ch2=(char*)malloc(200*sizeof(char));
	String s1,s2,s3,sub;
	cout<<"������ch1��ֵ��"<<endl;
	cin.getline(ch1,200);
	strAssign(s1,ch1);
	cout<<"ch��ֵ��s1��,s1��ֵ: ";
	print(s1);//ojbk
	cout<<"s1�ĳ��ȣ�"<<getLength(s1)<<endl;
	cout<<"������ch2��ֵ��"<<endl;
	cin.getline(ch2,200);
	strAssign(s2,ch2);
	cout<<"ch��ֵ��s2��,s2��ֵ: ";
	print(s2);//ojbk
	strConcat(s1,s2);//ojbk
	cout<<"s1��s2���Ӻ�,s1��ֵ: ";
	print(s1);
	strSub(s1,sub,2,3);//ojbk
	cout<<"s1�ĵ�2���ַ���ʼ����Ϊ3���Ӵ���";
	print(sub);
	cout<<"s1��s2�ȽϺ�Ľ����"<<strCmp(s1,s2)<<endl;//ojbk
	cout<<"s2��s1�ĵ�3���ַ���ʼ���״γ��ֵ�λ�ã�"<<strIndex(s1,s2,2)<<endl;//ojbk
	strInsert(s1,3,s2);//ojbk
	cout<<"s2����s1�ĵ�3���ַ����λ�ã�s1��ֵ��";
	print(s1);
	strDelete(s1,4,2);
	cout<<"s1��ɾ����4���ַ���ʼ�ĳ���Ϊ2���Ӵ���s1��ֵ��";//ojbk
	print(s1);
	char *ch3="www";
	strAssign(s3,ch3);
	strRep(s1,s2,s3);
	cout<<"��www�滻s1������s2�Ӵ�,s1��ֵΪ��";
	print(s1);
	return 0;
}
Status strAssign(String &s,char *ch) {
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
	for(i=0; i<length; ++i) {
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
	if(len==0) {
		sub.length=0;
		sub.ch=NULL;
		return ERROR;
	}
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
	i=i-1;
	String sub;
	strSub(s,sub,i+1,s.length-(i+1)+1);
	int j=i;
	s.ch=(char *)realloc(s.ch,(s.length+t.length)*sizeof(char));
	for(j=i; j<(i+t.length); ++j) {
		s.ch[j]=t.ch[j-i];
	}
	for(j; j<(s.length+t.length); ++j) {
		s.ch[j]=sub.ch[j-(i+t.length)];
	}
	s.length=s.length+t.length;
	return OK;
}

Status strDelete(String &S,int i,int len) {
	if(i<1||i>S.length||len>(S.length-i+1)||len<1) {
		return INFEASIBLE;
	}
	String sub;
	strSub(S,sub,i+len,S.length-len-i+1);
	if(i!=1) {
		S.ch=(char *)realloc(S.ch,(i-1)*sizeof(char));
		S.length=i-1;
		if(sub.ch!=NULL) {
			strConcat(S,sub);
		}
	} else {
		S=sub;
	}
	return OK;
}

Status strRep(String &S,String t,String r) {
	int i=1;
	while(i<S.length&&i!=-1) {
		i=strIndex(S,t,i);
		if(i>0) {
			strDelete(S,i,t.length);
			strInsert(S,i,r);
			i+=t.length;
		} else {
			break;
		}
	}
}
/*
	if(s.ch) {
		    free(s.ch);
        	}�������󡣶���s��s.ch��Ϊ�ա�
*/
