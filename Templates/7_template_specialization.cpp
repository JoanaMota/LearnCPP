#include <iostream>

template <class T>
void func(T a)
{
    std::cout << "Main template function: " << a << std::endl;
}
// Template specialization
template <>
void func<int>(int a)
{
    std::cout << "Specialized template for integer data type: " << a << std::endl;
}
// Overloading
void func(double a)
{
    std::cout << "Non Template function for double data type: " << a << std::endl;
}

template <class T>
class Test
{
public:
    Test()
    {
        std::cout << "Main Template Constructor" << std::endl;
    }
};

template <>
class Test<int>
{
public:
    Test()
    {
        std::cout << "Specialized Template Constructor" << std::endl;
    }
};

int main()
{
    // Function
    func<char>('b');             // Main template function
    func<int>(2);                // Specialization int
    func<float>(2.22);           // Main template function
    func(2.22);                  // Non-template function
    func<double>(4453545642.22); // Main template function
    func("Joana");               // Main template function

    // Class
    Test<std::string> t1;
    Test<double> t2; // Main Template Constructor
    Test<int> t3;    // Specialization int
    return 0;
}