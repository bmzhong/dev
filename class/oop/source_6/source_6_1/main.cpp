#include "Animal.cpp"
#include <iostream>
using namespace std;



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
    cout << endl;
    invoke_reference(animal);
    invoke_reference(fish);
    invoke_reference(owl);
    invoke_reference(parrot);

    system("pause");
    return 0;
}