#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void thickness(int) = 0;

    virtual void outline(int) = 0;
};

class LineSegment : public Shape
{
public:
    virtual void thickness(int n = 2)
    {
        if (n == 0)
            cout << "this line segment is invisible." << endl;
        else if (n == 1)
            cout << "this line segment thickness is 1." << endl;
        else if (n == 2)
            cout << "this line segment thickness is 2." << endl;
        else if (n == 3)
            cout << "this line segment thickness is 3." << endl;
        else
            cout << "this line segment thickness is not correct." << endl;
    }
    virtual void outline(int n=0)
    {
        if(n==0)
            cout<<"this line segment is solid."<<endl;
        else if(n==1)
            cout<<"this line segment is dashed."<<endl;
        else if(n==2)
            cout<<"this line segment is dotted."<<endl;
        else 
            cout<<"this line segment is not correct."<<endl;
    }
};

int main()
{
    LineSegment* line=new LineSegment();
    line->thickness(1);
    line->outline(1);
    system("pause");
    return 0;
}