#include <iostream>

// Sieve of Eratosthenes - https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int countPrimes(int n)
{
    if (n == 0 || n == 1)
        return 0;
    bool isPrime[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            isPrime[i] = false;
        else
            isPrime[i] = true;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j < n; j += i)
        {
            isPrime[j] = false;
        }
    }
    int counter{0};
    for (int i = 0; i < n; i++)
    {
        if (isPrime[i])
            counter++;
    }
    return counter;
}

int main()
{
    std::cout << countPrimes(10) << std::endl;
    return 0;
}