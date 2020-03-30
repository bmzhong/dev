#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Initialize\n";
    }
    ~A()
    {
        std::cout << "Clean up\n";
    }
};

A a;

main()
{
    std::cout << "Hello, world!\n";
  
    return 0;
}