#include <iostream>
#include "complex.hpp"

int main()
{

    CComplex c1(3, 2);
    CComplex c2(3, 3);
    CComplex c3 = c2;

    if (c1 == c2)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;

    if (c1 != c2)
        std::cout << "Not equal" << std::endl;
    else
        std::cout << "Equal" << std::endl;

    if (c3 == c2)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;

    if (c3 != c2)
        std::cout << "Not equal" << std::endl;
    else
        std::cout << "Equal" << std::endl;

    return 0;
}