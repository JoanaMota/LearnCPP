#include <iostream>

void test()
{
    std::cout << "Hello" << std::endl;
}
void test2(int val)
{
    std::cout << "Hello " << val << std::endl;
}

int main()
{
    test();

    void (*pTest)() = test; // pointer to a function called pTest that returns void and has no parameters
    // pTest = &test;
    // pTest = test; // This also works

    (*pTest)(); // We have to make sure that the dereference opeerator
                // applies to the pointer name and not a function named
    pTest();    // This also works

    void (*pTest2)(int) = test2;
    pTest2(8);

    return 0;
}