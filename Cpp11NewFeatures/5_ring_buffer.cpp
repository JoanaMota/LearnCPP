#include <iostream>
#include "ring.hpp"

int main()
{
    CRing<std::string> textRing(3);

    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");

    for (int i = 0; i < textRing.size(); i++)
    {
        std::cout << textRing.get(i) << std::endl;
    }

    return 0;
}