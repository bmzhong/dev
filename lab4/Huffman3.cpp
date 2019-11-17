#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct {
	char ch;
	int weight;
} Map,*PMap;
typedef struct {
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
} HTNode,*HuffmanTree;
typedef char ** HuffmanCode;
Status select(HuffmanTree &HT,int j,int &m1,int &m2);
Status createHuffmanTree(HuffmanTree &HT,int w[],int n);
Status HuffmanEncoding(HuffmanTree &HT,HuffmanCode &HC,int n);
Status printHuffmanCode(PMap map,HuffmanCode HC,int w[],int n);
int *createW(PMap map,int n);
PMap createMap(int &n);
int findSite(int weight,int *w,int n);
int findWeight(char ch,PMap map,int n);
char findChar(int weight,PMap map,int n);
Status decoding(HuffmanTree &HT,string code,string &decode,PMap map,int n,int *sep);
Status writeHfmTree(HuffmanTree HT,int n);
int *readToBeTran(int &i,PMap map,string &code,HuffmanCode HC,int n,int *w);
int  main() {
	int n;
	int count;
	string code,decode;
	int *w;
	int *sep;
	PMap map;
	map=createMap(n);
	w=createW(map,n);
	HuffmanTree HT;
	HuffmanCode HC;
	createHuffmanTree(HT,w,n);
	HuffmanEncoding(HT,HC,n);
	printHuffmanCode(map,HC,w,n);
	writeHfmTree(HT,n);
	sep=readToBeTran(count,map,code,HC,n,w);
	decoding(HT,code,decode,map,n,sep);
	return 	0;
}


int *createW(PMap map,int n) {
	int *w=(int *)malloc(n*sizeof(int));
	for(int i=0; i<n; ++i) {
		w[i]=map[i].weight;
	}
	return w;
}

PMap createMap(int &n) {
	char ch;
	int weight;
	PMap map=(PMap)malloc(sizeof(Map));
	n=0;
	cout<<"请输入字符和权值："<<endl;
	while(cin>>ch&&cin>>weight) {
		if(n==0) {
			map->ch=ch;
			map->weight=weight;
		} else {
			map=(PMap)realloc(map,(n+1)*sizeof(Map));
			map[n].ch=ch;
			map[n].weight=weight;
		}
		++n;
	}
	cin.clear();
	return map;
}

Status select(HuffmanTree &HT,int j,int &m1,int &m2) {
	HuffmanTree p=HT;
	int i=1;
	while((p+i)->parent!=0&&i<=j) {
		++i;
	}
	m1=i;
	++i;
	while((p+i)->parent!=0&&i<=j) {
		++i;
	}
	m2=i;
	++i;
	if((p+m1)->weight>(p+m2)->weight) {
		int t=m1;
		m1=m2;
		m2=t;
	}
	for(i; i<=j; ++i) {
		if((p+i)->parent!=0) {
			continue;
		} else {
			if((p+i)->weight<(p+m1)->weight&&(p+i)->weight<(p+m2)->weight) {
				m2=m1;
				m1=i;
				continue;
			} else if((p+i)->weight>=(p+m1)->weight&&(p+i)->weight<(p+m2)->weight) {
				m2=i;
			}
		}
	}
	return OK;
}

Status createHuffmanTree(HuffmanTree &HT,int w[],int n) {
	if(n<1) {
		return ERROR;
	}
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	HuffmanTree p=HT;
	int m1,m2;
	for(int i=1; i<=m; ++i) {
		(p+i)->parent=0;
		(p+i)->rchild=0;
		(p+i)->lchild=0;
		i<=n?(p+i)->weight=w[i-1]:(p+i)->weight=0;
	}
	for(int i=n+1; i<=m; ++i) {
		select(HT,i-1,m1,m2);
		(p+m1)->parent=i;
		(p+m2)->parent=i;
		(p+i)->lchild=m1;
		(p+i)->rchild=m2;
		(p+i)->weight=(p+m1)->weight+(p+m2)->weight;
	}
	return OK;
}

Status HuffmanEncoding(HuffmanTree &HT,HuffmanCode &HC,int n) {
	HuffmanTree p=HT;
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	char *cd=(char *)malloc(sizeof(n*sizeof(char)));
	cd[n-1]='\0';
	for(int i=1; i<=n; ++i) {
		int pos=n-1;
		int j=i;
		int k=(p+j)->parent;
		while(k!=0) {
			(p+k)->lchild==j?cd[--pos]='0':cd[--pos]='1';
			j=k;
			k=(p+j)->parent;
		}
		HC[i]=(char *)malloc((n-pos)*sizeof(char));
		strcpy(HC[i],&cd[pos]);
	}
	free(cd);
	return OK;
}

Status decoding(HuffmanTree &HT,string code,string &decode,PMap map,int n,int *sep) {
	int length=code.size();
	int k=2*n-1;
	int pos=0,i=0;
	while(code[i]) {
		if(code[i]=='0') {
			k=HT[k].lchild;
		} else if(code[i]=='1') {
			k=HT[k].rchild;
		} else {
			cout<<"密文有误"<<endl;
			return ERROR;
		}
		if(HT[k].lchild==0&&HT[k].rchild==0) {
			decode[pos++]=findChar(HT[k].weight,map,n);
			k=2*n-1;
		}
		++i;
	}
	cout<<"译码后的结果："<<endl;
	decode[pos]='\0';
	int j=0;
	int t=0;
	ofstream outfile("E:\\dev\\lab4\\textfile.txt");
	if(!outfile.is_open()) {
		cout<<"打开文件失败"<<endl;
		return ERROR;
	}
	for(int i=0; i<pos; ++i) {
		if(i-t==sep[j]) {
			cout<<endl;
			t=i;
			j++;
			outfile<<"\n";
		}
		cout<<decode[i];
		outfile<<decode[i];
	}
	cout<<endl;
	outfile.close();
	return OK;
}

Status printHuffmanCode(PMap map,HuffmanCode HC,int w[],int n) {
	cout<<"字符--权值--编码表："<<endl;
	for(int i=1; i<=n; ++i) {
		cout<<map[i-1].ch<<"  "<<w[i-1]<<"  "<<HC[i]<<endl;
	}
	return OK;
}
char findChar(int weight,PMap map,int n) {
	for(int i=0; i<n; ++i) {
		if(weight==map[i].weight) {
			return map[i].ch;
		}
	}
	return '\0';
}

int findSite(int weight,int *w,int n) {
	for(int i=0; i<n; ++i) {
		if(w[i]==weight) {
			return i;
		}
	}
	return -1;
}

int findWeight(char ch,PMap map,int n) {
	for(int i=0; i<n; ++i) {
		if(map[i].ch==ch) {
			return map[i].weight;
		}
	}
	cout<<"此字符不在输入的权值表中,输入不符合要求"<<endl;
	return -1;
}

Status writeHfmTree(HuffmanTree HT,int n) {
	ofstream outfile("E:\\dev\\lab4\\hfmTree.txt"); 
	if(!outfile.is_open()) {
		cout<<"打开文件失败"<<endl;
		return ERROR;
	}
	outfile<<"权值"<<"\t"<<"父节点"<<"\t"<<"左孩子"<<"\t"<<"右孩子"<<"\n";
	for(int i=1; i<=2*n-1; ++i) {
		outfile<<HT[i].weight<<"\t"<<HT[i].parent<<"\t";
		outfile<<HT[i].lchild<<"\t"<<HT[i].rchild<<"\n";
	}
	outfile.close();
	return OK;
}

int *readToBeTran(int &i,PMap map,string &code,HuffmanCode HC,int n,int *w) {
	int *sep=(int *)malloc(sizeof(int));
	i=0;
	string str1[100];
	ifstream infile("E:\\dev\\lab4\\toBeTran.txt");
//	infile.open("E:\\dev\\lab4\\toBeTran.txt");
	if(!infile.is_open()) {
		cout<<"打开文件失败"<<endl;
	}
	while(getline(infile,str1[i])) {
		if(i==0) {
			sep=(int *)malloc(sizeof(int));
			*sep=str1[i].size();
		} else {
			sep=(int *)realloc(sep,(i+1)*sizeof(int));
			sep[i]=str1[i].size();
		}
		for(int j=0; j<str1[i].size(); ++j) {
			int weight=findWeight(str1[i][j],map,n);
			int site=findSite(weight,w,n);
			code=code+HC[site+1];
		}
		++i;
	}
	cout<<"编码后的结果："<<endl;
	cout<<code<<endl;
	ofstream outfile("E:\\dev\\lab4\\codeFile.txt");
	if(!outfile.is_open()) {
		cout<<"打开文件失败"<<endl;
		return ERROR;
	}
	outfile<<code<<endl; 
	return sep;
}
