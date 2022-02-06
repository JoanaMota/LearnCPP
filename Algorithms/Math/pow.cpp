#include <iostream>

double myPow(double x, int n)
{
    if (0 == n)
    {
        return 1.0;
    }
    if (1 == n)
    {
        return x;
    }

    if (n < 0)
    {
        n = std::abs(n);
        x = 1 / x;
    }
    double output = x;

    for (int i = 1; i < n; i++)
    {
        output = output * x;
    }
    return output;
}

int main()
{
    std::cout << myPow(2.0, -2) << std::endl;
    return 0;
}