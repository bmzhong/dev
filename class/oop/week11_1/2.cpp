#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void draw() = 0;
};

class Pointer
{
private:
    int x, y;
    friend class Shape;

public:
    Pointer(int _x, int _y) : x(_x), y(_y) {}
};

class Circle : public Shape
{
private:
    int radius;
    Pointer point;

public:
    virtual void draw()
    {
        cout << "I am a circle." << endl;
    }
    Circle(int _radius, int _x, int _y) : radius(_radius), point(_x, _y) {}
};

class Square : public Shape
{
private:
    int length;

public:
    virtual void draw()
    {
        cout << "I am a square." << endl;
    }
    Square(int _length) : length(_length) {}
};

class Triangle : public Shape
{
private:
    int side1, side2, side3;

public:
    virtual void draw()
    {
        cout << "I am a triangle." << endl;
    }
    Triangle(int _side1, int _side2, int _side3) : side1(_side1), side2(_side2), side3(_side3) {}
};

bool intersection(Shape *shape1, Shape *shape2)
{
    shape1->draw();
    shape2->draw();
    if (1)
    {
        cout<< "they are overlap." <<endl;
        return true;
    }
    else
    {
        cout<<"they are not overlap."<<endl;
        return false;
    }
    
    
}

int main()
{
    Shape *circle1 = new Circle(1, 2, 3);
    Shape *circle2 = new Circle(2, 3, 4);
    Shape *square1 = new Square(1);
    Shape *square2 = new Square(2);
    Shape *triangle1 = new Triangle(2, 3, 4);
    Shape *triangle2 = new Triangle(3, 4, 5);

    intersection(circle1,circle2);
    intersection(circle1,square1);
    intersection(square1,square2);
    intersection(triangle1,triangle2);
    intersection(circle1,triangle2);
    intersection(square2,triangle2);

    system("pause");
    return 0;
}