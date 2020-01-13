#include<iostream>
using namespace std;
class Rectangle{
	public:
		int w,h;
	void init(int _w,int _h);
	int area();
	int perimeter();
};
void Rectangle::init(int _w,int _h){
	w=_w;
	h=_h;
}
int Rectangle::area(){
	return w*h;	
}
int Rectangle::perimeter(){
	return 2*(w+h);
}
int main(){
	int w,h;
	Rectangle r;
	cin>>w>>h;
	r.init(w,h);
	cout<<"area="<<r.area()<<endl;
	cout<<"primeter="<<r.perimeter()<<endl;
	return 0;	
}
