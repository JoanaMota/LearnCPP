#include <iostream>

template <class T>
void print(T n)
{
    std::cout << "Template version : " << n << std::endl;
}

void print(int value)
{
    std::cout << "Non-template function values: " << value << std::endl;
}

// Template function with no argument list
template <class T>
void show()
{
    std::cout << T() << std::endl;
}

int main()
{
    print<std::string>("Hello");
    print<int>(100);
    print("Hello World");
    print(6);   // The closer match is the non-template function version
    print<>(6); // This says that we want the template version even without the type

    // show(); // We cannot do this because the compiler cannot infer the type becuse the type is not in the argument list
    show<double>();

    return 0;
}