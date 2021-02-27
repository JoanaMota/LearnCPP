#include <iostream>

class Base
{
public:
    virtual void func(void) {}
};
class Derived : public Base
{
public:
};

int main()
{
    Base *b = new Derived;                   // Upcasting
    Derived *d = dynamic_cast<Derived *>(b); // Dynamic cast only works if it acts on a polymorphic class type
                                             // so the base must have at least one virtual functions

    if (b != NULL)
    {
        std::cout << "It is working" << std::endl;
    }
    else
    {
        std::cout << "Upcasting Base to Derived cannot be done" << std::endl;
    }

    return 0;
}