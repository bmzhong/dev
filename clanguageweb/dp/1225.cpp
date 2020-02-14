#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
namespace IO{
    inline LL read(){
        LL o=0,f=1;char c=getchar();
        while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
        while(c>='0'&&c<='9'){o=o*10+c-'0';c=getchar();}
        return o*f;
    }
}using namespace IO;
const int N=2e2+7;
int w[N],n;
LL s[N][N],ans;
void in(){
    n=read();
    for(int i=1;i<=n;i++)w[i]=read(),w[i+n]=w[i];//read（）为输入，等价cin，scanf，w[i+n]是把环拆完链。
}
void dispose(){
    for(int i=2;i<2*n;i++){
        for(int j=i-1;i-j<n&&j>=1;j--){
            for(int k=j;k<i;k++){
                s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+w[j]*w[k+1]*w[i+1]);//合并两个区间的能量
                if(s[j][i]>ans)ans=s[j][i];//和答案比大小
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    in();//输入
    dispose();//处理
    system("pause");
    return 0;
}