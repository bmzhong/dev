#include<stdio.h>
struct A {
	int x;
	int y;
};
struct A c[5001];
int n=0,res=0;
int main() {
	scanf("%d",&n);
	if(n==0) {
		printf("0\n");
		return 0;
	}
	int temp;
	scanf("%d",&temp);
	c[0].x=temp;
	c[0].y=1;
	int m=0;
	for(int i=1; i<n; ++i) {
		scanf("%d",&temp);
		if(temp==c[m].x) {
			++c[m].y;
		} else {
			c[++m].x=temp;
			c[m].y=1;
		}
	}
	++m;
	temp=0;
	for(int i=0; i<m; ++i) {
		if(c[i].y>=2) {
			temp=2;
			int k=1;
			while(i-k>=0&&i+k<m) {
				if(c[i-k].x==c[i+k].x&&c[i-k].y+c[i+k].y>2) {
					temp+=c[i-k].y+c[i+k].y;
					++k;
				} else {
					break;
				}
			}
			res=res>temp?res:temp;
		}
	}
	printf("%d\n",n-res);
	return 0;
}

