#include <iostream>

int reverse(int x)
{
    int output{0};
    while (x != 0)
    {
        int remainder = x % 10;
        x /= 10;
        if (std::abs(output) > (INT32_MAX - std::abs(remainder)) / 10)
        {
            return 0;
        }

        output = output * 10 + remainder;
    }
    return output;
}

int main()
{
    std::cout << reverse(123) << std::endl;
    std::cout << reverse(-123) << std::endl;
    std::cout << reverse(120) << std::endl;
    std::cout << reverse(1534236469) << std::endl;
    return 0;
}