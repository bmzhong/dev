#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
int getLength(char *str);
int match(char buf[1024],char *word);
int strCmp(char *sub,char *word);
Status assit(char filename[50],char *word);
Status strSub(char buf[1024],char *sub,int i,int len);
int main() {
 	char filename[50]="E:\\dev\\上机3\\test2.txt";
	char *word;
	word=(char *)malloc(36*sizeof(char));
	cin.getline(word,36);
	assit(filename,word);
	return 0; 
}

Status assit(char filename[50],char *word) {
	FILE *fp;
	int i=1;
	int row=1;
	int sum=0;
	int count=0;
	int length=getLength(word);
	char buf[1024];
	fp=fopen(filename,"r");
	if(fp==NULL) {
		return ERROR;
	} else {
		while(fgets(buf,sizeof(buf),fp)!=NULL) {
			sum=match(buf,word);
			if(sum!=0){
				cout<<"输入的单词在第"<<row<<"行出现的次数为"<<sum<<'\n';
				count+=sum;
				sum=0; 
				row++;
			}else{
				row++;
			} 
		}
	}
	cout<<endl;
	cout<<"输入的单词在文中出现的总次数为"<<count<<endl; 
	return OK;
}

int match(char buf[1024],char *word) {
	int i=1;
	int sum=0;
	char *sub;
	int length=getLength(buf);
	int j=getLength(word);
	sub=(char *)malloc(j*sizeof(char));
	while(buf[i-1]!='\n'&&i<=(length-j+1)) {
		strSub(buf,sub,i,j);
		if(strCmp(sub,word)==0) {
			sum++;
			i+=j;
		} else {
			++i;
		}
	}
	return sum;
}

int getLength(char *str) {
	int i=0;
	while(str[i]!='\0') {
		++i;
	}
	return i;
}

Status strSub(char buf[1024],char *sub,int i,int len) {
	for(int k=0; k<len; ++k) {
		sub[k]=buf[i-1+k];
	}
	return OK;
}

int strCmp(char *sub,char *word) {
	int i;
	for(i=0; i<getLength(word); ++i) {
		if((sub[i]-word[i])!=0) {
			break;
		} else if(i==(getLength(word)-1)) {
			return 0;
		}
	}
	return sub[i]-word[i];
}
