#include <iostream>

class Base1
{
public:
    virtual void display(int a = 0)
    {
        std::cout << "Base1 Class" << std::endl;
    }
};
class Derived1 : public Base1
{
public:
    void display(int a)
    {
        std::cout << "Derived1 Class val: " << a << std::endl;
    }
};
class Base2
{
public:
    virtual void display(int a = 0)
    {
        std::cout << "Base2 Class" << std::endl;
    }
};
class Derived2 : public Base2
{
public:
    void display(int a = 4)
    {
        std::cout << "Derived2 Class val: " << a << std::endl;
    }
};

int main()
{
    Derived1 d1;
    Base1 *b1 = &d1;
    b1->display();  // Uses base class default value
    b1->display(2); // Uses input value

    Derived2 d2;
    Base2 *b2 = &d2;
    b2->display();  // It still uses base class default value because default values
                    // are substituted at compile time on the base class pointer declaration
                    // Only the function is called at compile time
    b2->display(2); // Uses input value
    return 0;
}