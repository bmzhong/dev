#include <string>
#include <iostream>
using namespace std;
class Fighter
{
protected:
    string name;

public:
    Fighter() {}

    Fighter(string _name) : name(_name) {}

    void outTitle()
    {
        cout << "We are fighters." << endl;
    }

    virtual void hello()
    {
        cout << name << " is a fighter." << endl;
    }

    string get_name () const
    {
        return name;
    }
};

class Warrior : public Fighter
{
private:
    Fighter *mate;

public:
    Warrior(string _name, Fighter *_mate)
    {
        name = _name;
        mate = _mate;
    }
    void outTitle()
    {
        cout << "We are Warriors." << endl;
    }
    virtual void hello()
    {
        cout << name << " is a stronger warrior than " << mate->get_name() << endl;
    }
};
int main()

{
    Fighter *objs[2];

    objs[0] = new Fighter("Harry");

    Warrior Stallone("Stallone", objs[0]);

    objs[1] = &Stallone;

    cout << "== Test the class famliy ==" << endl;

    for (int i = 0; i < 2; i++)
    {

        objs[i]->outTitle();

        cout << "----  " << i + 1 << "  ----" << endl;

        objs[i]->hello();
    }

    cout << "==This is the end." << endl;

    delete objs[0];

    system("pause");

    return 0;
}