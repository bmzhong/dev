#include<iostream>
#include<cstdlib>
#include<cstring>
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
Status printHuffmanCode(HuffmanCode HC,int w[],int n);
int *createMap(PMap &map,int &n);
int  main() {
	int n;
	int *w;
	PMap map=(PMap)malloc(sizeof(Map));
	w=createMap(map,n);
	cout<<w<<endl;
	cout<<"map的值"<<endl;
	for(int i=0;i<n;++i){
		cout<<map[i].ch<<" "<<map[i].weight<<endl;
	}
	cout<<"main: w的值"<<endl;	
	for(int i=0;i<n;++i){
		cout<<w[i]<<" ";
	}
	HuffmanTree HT;
	HuffmanCode HC;
	createHuffmanTree(HT,w,n);
	HuffmanEncoding(HT,HC,n);
	printHuffmanCode(HC,w,n);
	return 	0;
}



int *createMap(PMap &map,int &n) {
	char ch;
	int weight;
	n=0;
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
	int *w=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;++i){
		w[i]=map[i].weight;
	}
	cout<<"createMap:w的值"<<endl;	
	for(int i=0;i<n;++i){
		cout<<w[i]<<" ";
	}
	cout<<endl;
	return w;
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
	cout<<"n的值"<<n<<endl;
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
		cout<<"HC"<<i<<":"<<endl; 
		cout<<HC[i]<<endl;
	}
	free(cd);
	return OK;
}

Status printHuffmanCode(HuffmanCode HC,int w[],int n) {
	cout<<"printHuffman:w的值:"<<endl;
	for(int i=0;i<n;++i){
		cout<<w[i]<<" "<<endl;
	}
	for(int i=1; i<=n; ++i) {
		cout<<w[i-1]<<"  "<<HC[i]<<endl;
	}
	return OK;
}
