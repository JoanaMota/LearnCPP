#include <iostream>

class BadParent
{
public:
    void print()
    {
        std::cout << "parent" << std::endl;
    }
};
class BadChild : public BadParent
{
public:
    void print()
    {
        std::cout << "child" << std::endl;
    }
};
class Parent
{
private:
    int a;

public:
    // Classes have to run the constructors of the parent classes in order to be instantiated.
    // So when we define a subclass we must have a default constructor in the parent class
    Parent() : a(0){};
    Parent(const Parent &other)
    {
        a = other.a;
        std::cout << "Copy Constructor parent" << std::endl;
    }
    // By adding the keyword virtual here C++ is going to create a table of function pointers
    // that point to the appropriate functions for the right types of object
    virtual void print()
    {
        std::cout << "parent" << std::endl;
    }
};
class Child : public Parent
{
private:
    int b;

public:
    Child() : b(0) {}
    void print()
    {
        std::cout << "child" << std::endl;
    }
};

int main()
{
    BadChild c1;
    BadParent &p1 = c1;
    p1.print(); // Since the function is not virtual there's no lookup mechanism for C++ to find the right method called

    Child c2;
    Parent &p2 = c2;
    p2.print();

    Parent p3 = Child(); // Calls the Parent class implicit copy constructor if it does not exist a defined Copy Constructor
    p3.print();

    return 0;
}