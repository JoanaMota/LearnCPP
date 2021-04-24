#include <iostream>

// pFunc - function pointer
void test(void (*pFunc)())
{
    pFunc();
}

void testGreet(void (*pGreet)(std::string))
{
    pGreet("Bob");
}

void runDivide(double (*pDivide)(double a, double b), double a, double b)
{
    auto rval = pDivide(a, b);
    std::cout << rval << std::endl;
}

class CTest
{
private:
    int one{1};
    int two{2};

public:
    void run()
    {
        int three{3};
        int four{4};

        auto pLambda = [three, this, four]() {
            one = 10;
            std::cout << one << ", " << two << std::endl;
            std::cout << three << ", " << four << std::endl;
        };
        pLambda();
    }
};

int main()
{
    // Intro
    auto func = []() { std::cout << "Hello" << std::endl; };
    func();

    test(func);
    test([]() { std::cout << "Hello" << std::endl; });

    // Parameters
    auto pGreet = [](std::string name) { std::cout << "Hello " << name << std::endl; };
    pGreet("Joana");
    testGreet(pGreet);
    testGreet([](std::string name) { std::cout << "Hello " << name << std::endl; });

    // Return Types
    // one return type, the compile infers the type by himself
    auto pSum = [](double a, double b) { return a + b; };
    // more return types, we need to specify the return type
    auto pDivide = [](double a, double b) -> double {
        if (b == 0.0)
        {
            return 0;
        }
        return a / b;
    };
    std::cout << pSum(10.0, 5.0) << std::endl;
    std::cout << pDivide(10.0, 5.0) << std::endl;
    runDivide(pDivide, 20, 10);

    // Lambda Capture Expression
    int one = 1;
    int two = 2;
    int three = 3;

    // Capture one and two by value
    [one, two]() { std::cout << one << ", " << two << std::endl; }();
    // Capture all local variables by value
    [=]() { std::cout << one << ", " << two << std::endl; }();

    // Capture three by reference
    [&three]() {
        three = 7;
        std::cout << three << std::endl; // 7
    }();
    // Capture all local variables by value but capture three by reference
    [=, &three]() {
        // two = 8; Can't change variables passed by value
        std::cout << one << ", " << two << ", " << three << std::endl;
        three = 9;
    }();
    std::cout << three << std::endl; // 9

    // Capture all local variables by reference
    [&]() {
        one = 10;
        two = 20;
        three = 30;
        std::cout << one << ", " << two << ", " << three << std::endl; // 10, 20, 30
    }();
    // Capture all local variables by reference with some exceptions
    [&, two, three]() {
        one = 100;
        // two = 20; Now this is passed by value so it can't be changed
        // three = 30; Now this is passed by value so it can't be changed
        std::cout << one << ", " << two << ", " << three << std::endl; // 100, 20, 30
    }();

    // Capturing this with Lambda Expresions
    CTest test;
    test.run();

    // Mutable in Lambdas
    int var1 = 5;
    [var1]() mutable {var1 = 6; std::cout << var1 << std::endl; }();         //6
    std::cout << var1 << std::endl; // 5
    return 0;
}