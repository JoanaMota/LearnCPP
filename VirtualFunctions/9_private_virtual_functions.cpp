#include <iostream>
class Base
{
public:
    virtual void display(void)
    {
        std::cout << "Base Class display" << std::endl;
    }

private:
    virtual void func(void)
    {
        std::cout << "Base Class func" << std::endl;
    }
    friend int main();
};
class Derived : public Base
{
private:
    void display(void)
    {
        std::cout << "Derived Class display" << std::endl;
    }

public:
    void func(void)
    {
        std::cout << "Derived Class func" << std::endl;
    }
};

int main()
{
    Base *b = new Derived; // Upcasting
    b->display();          // This code works because base class
                           // defines a public interface and derived class overrides
                           // it in its implementation
    b->func();

    delete b;
    return 0;
}