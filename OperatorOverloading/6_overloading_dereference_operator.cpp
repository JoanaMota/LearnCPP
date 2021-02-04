#include <iostream>
#include "complex.hpp"

int main()
{

    CComplex c1(3, 2);
    std::cout << c1 << std::endl;
    std::cout << *c1 << std::endl; // The conjugate of the complex number
    std::cout << *c1 << std::endl; // It only returns a new object and does not change the input object
    std::cout << *c1 + CComplex(4, 3) << std::endl;
    std::cout << *c1 + *CComplex(4, 3) << std::endl;
    // Here the dereference operator * is applied before the plus
    // but this can also be the other way around

    return 0;
}