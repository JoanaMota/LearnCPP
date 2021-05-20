#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
    std::cout << a << " + " << b << " + " << c << " = ";
    return a + b + c;
}

int run(std::function<int(int, int)> func)
{
    func(7, 3);
}

class CTest
{
public:
    int multiply(int a, int b)
    {
        std::cout << a << " x " << b << " = ";
        return a * b;
    }
};

int main()
{
    std::cout << add(1, 2, 3) << std::endl;

    std::function<int()> calculator1 = std::bind(add, 1, 2, 3);
    std::cout << calculator1() << std::endl;
    std::function<int(int, int, int)> calculator2 = std::bind(add, std::placeholders::_1, std::placeholders::_1, std::placeholders::_1);
    std::cout << calculator2(3, 4, 5) << std::endl; // 3 + 3 + 3
    std::function<int(int, int, int)> calculator3 = std::bind(add, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    std::cout << calculator3(1, 4, 5) << std::endl; // 1 + 4 + 5
    std::function<int(int, int, int)> calculator4 = std::bind(add, std::placeholders::_1, 5, 10);
    std::cout << calculator4(1, 4, 5) << std::endl; // 1 + 5 + 10
    std::function<int(int, int, int)> calculator5 = std::bind(add, std::placeholders::_3, std::placeholders::_2, std::placeholders::_1);
    std::cout << calculator5(1, 4, 5) << std::endl; // 5 + 4 + 1
    std::function<int(int, int)> calculator6 = std::bind(add, std::placeholders::_2, std::placeholders::_1, 10);
    std::cout << calculator6(5, 20) << std::endl; // 20 + 5 + 10

    std::cout << run(calculator6) << std::endl;

    CTest test;
    auto calc = std::bind(&CTest::multiply, test, 10, std::placeholders::_1);
    std::cout << calc(5) << std::endl; // 10 * 5

    return 0;
}