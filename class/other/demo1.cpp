#include <iostream>
using namespace std;
class Rectangle
{
public:
	int w, h;
	void init(int _w, int _h);
	int area();
	int perimeter();
};
void Rectangle::init(int _w, int _h)
{
	w = _w;
	h = _h;
}
int Rectangle::area()
{
	return w * h;
}
int Rectangle::perimeter()
{
	return 2 * (w + h);
}
int main()
{
	char ww='a';
	const char yy='d';
	ww=yy;
	int w = 5, h = 6;
	Rectangle r;
	Rectangle *p = &r;
	Rectangle &y = r;
	r.init(w, h);
	r.w = 10;
	p->init(3, 4);
	cout << y.w << endl;
	cout << p->w << endl;
	system("pause");
	return 0;
}
