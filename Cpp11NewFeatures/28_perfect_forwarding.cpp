#include <iostream>

class CTest
{
};

template <typename T>
void call(T &&arg)
{
    check(arg);
}
template <typename T>
void callPF(T &&arg)
{
    check(std::forward<T>(arg));
    // same as
    // check(static_cast<T>(arg));
}

void check(CTest &test)
{
    std::cout << "Lvalue" << std::endl;
}
void check(CTest &&test)
{
    std::cout << "Rvalue" << std::endl;
}

int main()
{
    auto &&t = CTest(); // RValue Reference
    CTest test;         // LValue reference
    auto &&t1 = test;
    call(CTest());
    // CTest() is an RValue but when we use it in call it is recognized as an LValue because a reference collapsing occurs.
    // To fix this reference collapse we can used perfect forwarding.
    callPF(CTest()); // Pass the RValue with perfect forwarding we now get the corret usage
    call(test);
    return 0;
}
