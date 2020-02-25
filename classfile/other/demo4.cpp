#include <iostream>
using namespace std;
class CTyre
{
public:
    int radius;
    int width;

public:
    CTyre(int _radius, int _width) : radius(_radius), width(_width) {}
    CTyre(CTyre &c){
        cout<<"我是CTyre的复制构造函数"<<endl;
    }
};

class CEngine{

};
class CCar{
    private:
        int price;
        CTyre tyre;
        CEngine c;
    public:
        CCar(int p,int r,int w);
        int getRadius(){
            return tyre.radius;
        }
};

CCar::CCar(int p,int r,int w):price(p),tyre(r,w){

}

int main(){
    CCar c(1,2,3),c1(c);
    cout<<c1.getRadius()<<endl;
    system("pause");
    return 0;
}