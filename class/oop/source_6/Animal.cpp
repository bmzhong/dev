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

int main()
{
    Animal animal("animal A01");
    Dog dog("Dog D01");
    Bird bird("Bird B01");
    cout << "call iam :" << endl;
    animal.iam();
    dog.iam();
    bird.iam();
    cout << endl;
    cout << "call hello :" << endl;
    animal.hello();
    dog.hello();
    bird.hello();
    cout << endl;
    cout << "call common :" << endl;
    animal.common();
    dog.common();
    bird.common();
    cout << endl;

    Animal *pa, *pd, *pb;
    pa = &animal;
    pd = &dog;
    pb = &bird;
    cout << "pointers call iam :" << endl;
    pa->iam();
    pd->iam();
    pb->iam();
    cout << endl;
    cout << "pointers call hello :" << endl;
    pa->hello();
    pd->hello();
    pb->hello();
    cout << endl;
    cout << "pointers call common :" << endl;
    pa->common();
    pd->common();
    pb->common();
    cout << endl;

    Animal &ra = animal;
    Animal &rd = dog;
    Animal &rb = bird;
    cout << "references call iam :" << endl;
    ra.iam();
    rd.iam();
    rb.iam();
    cout << endl;
    cout << "references call hello :" << endl;
    ra.hello();
    rd.hello();
    rb.hello();
    cout << endl;
    cout << "references call common :" << endl;
    ra.common();
    rd.common();
    rb.common();
    cout << endl;

    Fish fish("fish01");
    Owl owl("owl01");
    Parrot parrot("parrot01");
    invoke_pointer(&animal);
    invoke_pointer(&fish);
    invoke_pointer(&owl);
    invoke_pointer(&parrot);
    cout<<endl;
    invoke_reference(animal);
    invoke_reference(fish);
    invoke_reference(owl);
    invoke_reference(parrot);

    system("pause");
    return 0;
}
