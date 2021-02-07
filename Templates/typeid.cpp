#include <iostream>
#include <typeinfo>

class Base
{
public:
    virtual void myfunc() {}
};

class Derived : public Base
{
};

int main()
{

    int e;
    unsigned f;
    char g;
    float h;
    double i;
    std::cout << "int:" << typeid(e).name() << std::endl; //prints "i"
    std::cout << "unsigned:" << typeid(f).name() << std::endl;
    std::cout << "char:" << typeid(g).name() << std::endl;
    std::cout << "float:" << typeid(h).name() << std::endl;
    std::cout << "double:" << typeid(i).name() << std::endl;

    Derived *pd = new Derived;
    Base *pb = pd;
    std::cout << typeid(pb).name() << std::endl;  //prints "P4Base"
    std::cout << typeid(*pb).name() << std::endl; //prints "7Derived"
    std::cout << typeid(pd).name() << std::endl;  //prints "P7Derived"
    std::cout << typeid(*pd).name() << std::endl; //prints "7Derived"
    delete pd;
}