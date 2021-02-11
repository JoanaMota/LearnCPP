#include <iostream>

template <class T = float, int i = 5>
class A
{
public:
    A();
    int value;
};

// Explicit Specialization
// --Default Arguments
template <>
class A<>
{
public:
    A();
};
// --Specific Arguments
template <>
class A<double, 10>
{
public:
    A();
};

// Constructos Declaration
template <class T, int i>
A<T, i>::A() : value(i)
{
    std::cout << "Primary Template " << value << std::endl;
}
A<>::A()
{
    std::cout << "Explicit Specialization"
              << " Default Arguments" << std::endl;
}
A<double, 10>::A()
{
    std::cout << "Explicit Specialization"
              << " <double,10>" << std::endl;
}

int main()
{
    A<int, 8> a1;     //Primary Template
    A<> a2;           // Explicit Specialization Default Arguments
    A<double, 10> a3; // Explicit Specialization <double,10>
    return 0;
}