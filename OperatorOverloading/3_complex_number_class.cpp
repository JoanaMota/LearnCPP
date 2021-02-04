#include <iostream>
#include "complex.hpp"

int main()
{
    CComplex c1;       //Default Constructor
    CComplex c2(2, 3); //Parameterized Constructor
    CComplex c3 = c2;  //Copy Constructor
    CComplex c4(c2);   //Copy Constructor
    c1 = c2;           //Assignment Operator

    CComplex c5(5, 10);
    std::cout << c1 << std::endl;
    std::cout << c5 << std::endl;
    std::cout << c2 << " and " << c5 << std::endl;

    return 0;
}