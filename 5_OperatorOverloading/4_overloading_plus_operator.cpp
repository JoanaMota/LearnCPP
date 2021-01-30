#include <iostream>
#include "complex.hpp"

int main()
{

    CComplex c1(3, 4);
    CComplex c2(2, 3);

    CComplex c3 = c1 + c2;

    std::cout << c1 << " + " << c2 << " = " << c3 << std::endl;
    std::cout << c1 + c2 + c3 << std::endl;

    CComplex c4(4, 2);
    CComplex c5 = c4 + 7;
    std::cout << c5 << std::endl;
    std::cout << c4 + 10 << std::endl;
    std::cout << 10 + c4 << std::endl;
    CComplex c6(1, 7);
    std::cout << 7 + c1 + c2 + 8 + 9 + c6 << std::endl;

    return 0;
}