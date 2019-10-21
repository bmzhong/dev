#include<stdio.h>
#include<string.h>
int main(){
	char cArr[]={'I','L','O','V','E','C'};
	char sArr[]="ILOVEC";
	printf("c的长度=%d\n",sizeof(cArr));
	printf("s的长度=%d\n",sizeof(sArr));
	printf("c的长度=%d\n",strlen(cArr));
	printf("s的长度=%d\n",strlen(sArr));
	printf("c=%s\n",cArr);
	printf("s=%s\n",sArr);
	return 0;	 
}
