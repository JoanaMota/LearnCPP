#include <iostream>

bool isPowerOfThreeRecur(int n)
{
    if (n == 1)
        return true;

    if (n < 1)
        return false;

    return isPowerOfThreeRecur(n / 3.0);
}
bool isPowerOfThree(int n)
{
    if (n == 0)
        return false;
    while (n != 1)
    {
        if (0 == (n % 3))
        {
            n = n / 3;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha << isPowerOfThreeRecur(9) << std::endl;
    return 0;
}