#include <iostream>
int mirrorReflection(int p, int q)
{
    if (p == q)
        return 1;
    if (p == q * 2)
        return 2;
    if (q == 0)
        return 0;
    while (p % 2 == 0 && q % 2 == 0)
    {
        p /= 2;
        q /= 2;
    }
    if (p % 2 == 0)
        return 2;
    else if (q % 2 == 0)
        return 0;

    return 1;
}
int main()
{
    std::cout << mirrorReflection(3, 1) << std::endl;
    return 0;
}