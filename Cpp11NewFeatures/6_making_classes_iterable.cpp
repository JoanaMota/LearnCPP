#include <iostream>
#include "ring.hpp"

int main()
{
    CRing<std::string> textRing(3);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");

    for (CRing<std::string>::CIterator it = textRing.begin(); it != textRing.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    for (auto value : textRing)
    {
        std::cout << value << std::endl;
    }

    return 0;
}