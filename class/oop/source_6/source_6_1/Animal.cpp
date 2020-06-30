#include <iostream>
#include <string>
using namespace std;
class Animal
{
protected:
    string name;

public:
    Animal(const char *nm = "A") : name("A")
    {
        if (nm != NULL)
            name = nm;
    }

    Animal(const string &nm) : name(nm) {}

    virtual void iam()
    {
        cout << "Animal " << name << "\n";
    }

    void hello()
    {
        cout << "Animal::hello from " << name << endl;
    }

    void common()
    {
        cout << "Animal::common" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(const char *_name = "a dog") : Animal(_name) {}

    Dog(const string &_name) : Animal(_name) {}

    virtual void iam()
    {
        cout << "Dog " << name << "\n";
    }

    void hello()
    {
        cout << "Dog::hello from " << name << endl;
    }
};

class Bird : public Animal
{
public:
    Bird(const char *_name = "a bird") : Animal(_name) {}

    Bird(const string &_name) : Animal(_name) {}

    virtual void iam()
    {
        cout << "Bird " << name << "\n";
    }

    void hello()
    {
        cout << "Bird::hello from " << name << endl;
    }
};
//Fish 不重置iam;
class Fish : public Animal
{
public:
    Fish(const char *_name = "a fish") : Animal(_name) {}

    Fish(const string &_name) : Animal(_name) {}
};
//Owl 是Animal派生类的派生类，重置iam;
class Owl : public Bird
{
public:
    Owl(const char *_name = "a owl") : Bird(_name) {}

    Owl(const string &_name) : Bird(_name) {}

    virtual void iam()
    {
        cout << "Owl " << name << "\n";
    }
};
//Parrot 是Animal派生类的派生类，不重置iam;
class Parrot : public Bird
{
public:
    Parrot(const char *_name = "a parrot") : Bird(_name) {}

    Parrot(const string &_name) : Bird(_name) {}
};

//通过animal指针调用iam;
void invoke_pointer(Animal *animal)
{
    animal->iam();
}
//通过animal引用调用iam;
void invoke_reference(Animal &animal)
{
    animal.iam();
}