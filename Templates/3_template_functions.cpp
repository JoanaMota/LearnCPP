#include <iostream>

template <class T>
void print(T n)
{
    std::cout << n << std::endl;
}

template <class T>
T getLarger(const T &n1, const T &n2)
{
    return (n1 > n2) ? n1 : n2;
}

int main()
{
    print<std::string>("Hello");
    print<int>(100);
    print("Hello World");

    std::cout << "The larger between integers 1 and 5 is " << getLarger(1, 5) << std::endl;
    std::cout << "The larger between floats 10.4 and 5.2 is " << getLarger(10.4, 5.2) << std::endl;
    std::cout << "The larger between chanrs a and b is " << getLarger<std::string>("a", "b") << std::endl;
    // We need to specify that is string otherwise it will consider the input to be char[2]
    return 0;
}