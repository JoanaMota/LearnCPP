#include <iostream>

class Base
{
public:
    virtual ~Base()
    {
        std::cout << "Base Class Destructor" << std::endl;
    }
};
class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived Class Destructor" << std::endl;
    }
};

int main()
{
    Base *b = new Derived; // Upcasting
    delete b;
    return 0;
}