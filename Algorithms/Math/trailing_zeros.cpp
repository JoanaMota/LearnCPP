#include <iostream>

int trailingZeroes(int n)
{
    if (0 == n)
    {
        return 0;
    }

    int nrTrailingZeros{0};
    for (int i = 5; i <= n; i *= 5)
    {
        nrTrailingZeros += (int)(n / i);
    }
    return nrTrailingZeros;
}

int main()
{
    std::cout << trailingZeroes(5) << std::endl;
    return 0;
}