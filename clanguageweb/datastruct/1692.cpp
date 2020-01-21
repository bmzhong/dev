#include<iostream>
using namespace std;
struct A{
    int r;
    int data;
    int c;
};
struct B{
    A a[10000];
    int mu,nu,tu=0;
};
int main(){
    int r,c1,d;
    B m,t;
    scanf("%d %d",&r,&c1);
    int pos=0;
    for(int i=0;i<r;++i){
        for(int j=0;j<c1;++j){
            scanf("%d",&d);
            if(d!=0){
                m.a[pos].r=i;
                m.a[pos].c=j;
                m.a[pos].data=d;
                pos++;
            }
        }
    }
    m.mu=r;
    m.nu=c1;
    m.tu=pos;
    t.mu=m.nu;
    t.nu=m.mu;
    t.tu=m.tu;
    pos=0;
    for(int i=0;i<m.nu;++i){
        for(int j=0;j<m.tu;++j){
            if(m.a[j].c==i){
                t.a[pos].r=m.a[j].c;
                t.a[pos].data=m.a[j].data;
                t.a[pos].c=m.a[j].r;
                ++pos;
            }
        }
    }
    pos=0;
    for(int i=0;i<t.mu;++i){    
        for(int j=0;j<t.nu-1;++j){
            if(t.a[pos].c==j&&t.a[pos].r==i){
                printf("%d ",t.a[pos].data);
                ++pos;
            }else{
                printf("0 ");
            }
        }
        if(t.a[pos].c==t.nu-1&&t.a[pos].r==i){
            printf("%d\n",t.a[pos].data);
            ++pos;
        }else{
            printf("0\n");
        }
    }
    system("pause");
    return 0;

}