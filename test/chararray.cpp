#include<stdio.h>
#include<string.h>
int main(){
	char cArr[]={'I','L','O','V','E','C'};
	char sArr[]="ILOVEC";
	printf("c�ĳ���=%d\n",sizeof(cArr));
	printf("s�ĳ���=%d\n",sizeof(sArr));
	printf("c�ĳ���=%d\n",strlen(cArr));
	printf("s�ĳ���=%d\n",strlen(sArr));
	printf("c=%s\n",cArr);
	printf("s=%s\n",sArr);
	return 0;	 
}
