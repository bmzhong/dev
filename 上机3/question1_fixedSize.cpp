#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
#define MAXSTRLEN 1000
#define OK 1
#define ERROR 0
typedef int Status;
typedef char String[MAXSTRLEN+1];
Status strAssign(String &str,char *ch);
Status strConcat(String s1,String s2);
Status strSub(String &s1,String s,int i,int len);
Status print(String s);
Status strConcat(String s1,String s2,String &s);
Status strInsert(String &s,int i,String t);
Status strDelete(String &s,int i,int len);
Status strRep(String &s,String t,String r);
int getLength(String str);
int strIndex(String s,String t,int pos);
int strCmp(String s1,String s2);
int main() {
	String s1,s2,s3,s;
	char *ch1,*ch2,*ch3;
	ch1=(char*)malloc(sizeof(char)*50);
	ch2=(char*)malloc(sizeof(char)*50);
	ch3=(char*)malloc(sizeof(char)*50);
	cin.getline(ch1,50);
	cin.getline(ch2,50);
	cin.getline(ch3,50);
	strAssign(s1,ch1);
	strAssign(s2,ch2);
	strAssign(s3,ch3);
	print(s1);
	print(s2);
	print(s3);
	cout<<"s1,s2比较后的结果："<<endl;
	cout<<strCmp(s1,s2)<<endl;
	cout<<"子串s2在主串s1的pos位置后首次出现的位置："<<endl;
	cout<<strIndex(s1,s2,1)<<endl;
	cout<<"将s2插入在s1的第i个位置后"<<endl;
	strInsert(s1,3,s2);
	print(s1);
	cout<<"用s3替换s1中所有出现的s2："<<endl; 
	strRep(s1,s2,s3);
	print(s1);
	cout<<"删除s1第i个位置后长度为len的子串"<<endl;
	strDelete(s1,3,3);
	print(s1);
//  "带三个参数的字符串连接函数" 即将s1,s2连接起来赋值给s 
//	strConcat(s1,s2,s);
//	print(s);
//	cout<<getLength(s)<<endl;
//  带两个参数的字符串连接函数，即将s2连在s1的后面 
	strConcat(s1,s2);
	cout<<"s1,s2连接后的字符串："<<endl; 
	print(s1);
	cout<<"s1的长度："<<getLength(s1)<<endl;
	strSub(s2,s1,2,3);
	cout<<"s1的子串："<<endl;
	print(s2);
	return 0;
}

int getLength(String str) {
	return (int)str[0];
}

Status strAssign(String &str,char *ch) {
	int sum=0;
	while(ch[sum]!='\0') {
		++sum;
	}
	if(sum>MAXSTRLEN) {
		for(int i=1; i<MAXSTRLEN; ++i) {
			str[i]=*(ch+i-1);
		}
		str[0]=(char)MAXSTRLEN;
	} else {
		str[0]=(char)sum;
		for(int i=1; i<=sum; ++i) {
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

Status print(String s) {
	for(int i=1; i<=(int)s[0]; ++i) {
		cout<<s[i];
	}
	cout<<endl;
	return OK;
}

Status strConcat(String s1,String s2) {
	int length1=getLength(s1);
	int length2=getLength(s2);
	for(int i=length1+1; i<=(length1+length2)&&(i<=MAXSTRLEN); ++i) {
		s1[i]=s2[i-length1];
	}
	if(MAXSTRLEN>(length1+length2)) {
		s1[0]=(char)(length1+length2);
	} else {
		s1[0]=(char)MAXSTRLEN;
	}
	return OK;
}

Status strSub(String &s1,String s,int i,int len) {
	if(i<1||i>getLength(s)||len<0||len>(getLength(s)-i+1)) {
		return ERROR;
	}
	if(len==0) {
		s1[0]=(char)0;
		return OK;
	}
	for(int j=1; j<=len; ++j) {
		s1[j]=s[j+i-1];
	}
	s1[0]=len;
	return OK;
}

int strCmp(String s1,String s2) {
	for(int i=1; i<=getLength(s1)&&i<=getLength(s2); ++i) {
		if(s1[i]!=s2[i]) {
			return s1[i]-s2[i];
		}
	}
	return s1[0]-s2[0];
}

int strIndex(String s,String t,int pos) {
	if(pos>((int)s[0]-(int)t[0]+1)||((int)t[0]>(int)s[0])) {
		return ERROR;
	}
	String sub;
	int slength=getLength(s);
	int tlength=getLength(t);
	int i=pos;
	while(i<=slength-tlength-1) {
		strSub(sub,s,i,tlength);
		if(strCmp(sub,t)==0) {
			return i;
		} else {
			++i;
		}
	}
	return -1;
}

Status strInsert(String &s,int i,String t) {
	if(i<0||i>(getLength(s)+1)||MAXSTRLEN<(getLength(s)+getLength(t))) {
		return ERROR;
	}
	int j;
	String sub;
	strSub(sub,s,i,(int)s[0]-i+1);
	for(j=i; j<(i+(int)t[0]); ++j) {
		s[j]=t[j-i+1];
	}
	s[0]=(char)(s[0]+t[0]);
	for(j; j<=(int)s[0]; ++j) {
		s[j]=sub[j-(i+(int)t[0])+1];
	}
	return OK;
}

Status strDelete(String &s,int i,int len) {
	if(i<1||i>s[0]||(int)s[0]<i+len-1) {
		return ERROR;
	}
	String sub;
	int slength=(int)s[0];
	strSub(sub,s,i+len,(int)s[0]-(i+len)+1);
	strInsert(s,i,sub);
	s[0]=(char)(slength-len);
	return OK;
}

Status strRep(String &s,String t,String r) {
	int i=1;
	while(i<=((int)s[0]-(int)t[0]+1)) {
		i=strIndex(s,t,1);
		if(i>0) {
			strDelete(s,i,(int)t[0]);
			strInsert(s,i,r);
			i+=(int)t[0];
			continue;
		} else {
			break;
		}
	}
	return OK;
}
