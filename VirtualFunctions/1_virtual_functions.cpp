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

int main()
{
    Derived d;
    Base *b = &d;
    // If display function was not virtual it would print Base Class
    b->display(); // Late bidding
    return 0;
}