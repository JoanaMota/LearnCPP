#include <iostream>

class Base
{
public:
    virtual ~Base() = 0;
};
Base::~Base()
{
    std::cout << "Pure Virtual Base Class Destructor" << std::endl;
}
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
    Derived d;
    Base *b = &d;

    return 0;
}