#include <iostream>
class Base
{
public:
    virtual void display(void)
    {
        std::cout << "Base Class display" << std::endl;
    }
};
class Derived : public Base
{
private:
    void display(void)
    {
        std::cout << "Derived Class display" << std::endl;
    }
};

int main()
{
    Base b;
    Derived d;
    Base *ptrB = &d;
    // Here display is called through
    // object of the class (it will be resolved at compile
    // time) so it can be inlined.
    b.display();
    // Here virtual function is called through pointer,
    // so it cannot be inlined
    ptrB->display();
    return 0;
}