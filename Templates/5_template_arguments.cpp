#include <iostream>
#include <typeinfo>

// Template Type Parameters
template <class T>
void print(T n)
{
    std::cout << n << std::endl;
}

// Template Non-Type Parameter
template <int i> // Non-Type Template Paramter which is an integer
class A
{
};

template <int i>
void function()
{
    std::cout << i << std::endl;
}

template <void (*func)(int)> // Non-Type Template Paramter which is a returning function void
void C(){};

void func(int);
struct MyStruct
{
    static void staticFunc(int);
};

// Template Template Parameters
template <template <typename T, typename V> class U>
class MyClass
{
public:
    U<int, double> a1;
    U<std::string, int> b1;
};

template <class T, class V>
class Test
{
public:
    int x;
};

int main()
{
    A<3> a1;
    A<sizeof(std::string)> a2;

    function<4>();
    // function<4.0>(); // Error

    C<&func>();
    C<&MyStruct::staticFunc>();

    double test1 = 20.0;

    MyClass<Test> myClass;
    std::cout << "type of myClass.a1.x: " << typeid(myClass.a1.x).name() << std::endl;
    std::cout << "type of test1: " << typeid(test1).name() << std::endl;

    return 0;
}