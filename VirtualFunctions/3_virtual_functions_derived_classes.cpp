#include <iostream>

class Base
{
public:
    virtual void display(void)
    {
        std::cout << "Base Class" << std::endl;
    }
};
class Derived : public Base
{
public:
    void display(void)
    {
        std::cout << "Derived Class" << std::endl;
    }
};
class DerivedDerived : public Derived
{
public:
    void display(void)
    {
        std::cout << "DerivedDerived Class" << std::endl;
    }
};

int main()
{
    Base b;
    b.display();
    Derived d;
    d.display();
    DerivedDerived dd;
    dd.display();

    Derived d1;
    DerivedDerived dd1;
    Base *b1 = &d1;
    Base *bb1 = &dd1;

    b1->display();
    bb1->display();

    DerivedDerived dd2;
    Derived *d2 = &dd2;
    d2->display();

    return 0;
}