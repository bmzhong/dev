#include<stdio.h>
int n,m;
int jia[1000000],yi[1000000],t[1000000],r[1000000];
int main() {
	while(scanf("%d",&n)!=EOF){
		m=0;
		char temp=getchar();
		while(1){
			temp=getchar();
			if(temp=='\n')
				break;
			else
				jia[m++]=temp;
		}
		for(int i=0;i<m;++i){
			scanf("%c",&yi[i]);
		}
		temp=getchar();
		for(int i=0;i<n;++i){
			int r1=0,r2=0;
			for(int j=0;j<m;++j){
				scanf("%c",&t[j]);
				if(t[j]==jia[j])
					++r1;
				if(t[j]==yi[j])
					++r2;
			}
			temp=getchar();
			r[i]=r1>r2?r1:r2;
		}
		for(int i=0;i<n;++i){
			printf("%d\n",r[i]);
		}
	}
	return 0;
}
