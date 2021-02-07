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

template <class T>
void func(T x, T y)
{
    std::cout << "Template function" << std::endl;
}
void func(int x, int y)
{
    std::cout << "Non Template function" << std::endl;
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

    func(1, 2);
    func<>(1, 2);
    func("a", "b");
    func(1, 'b'); // Calls non-template Function because the non-template function resolves this function
                  // call after using the standard convertion from character to integer

    return 0;
}