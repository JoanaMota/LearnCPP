#include <iostream>
#include <vector>

// Sieve of Eratosthenes - https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int countPrimes(int n)
{
    if (0 == n || 1 == n)
    {
        return 0;
    }
    std::vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (!primes[i])
        {
            continue;
        }
        for (int j = i * i; j < n; j += i)
        {
            primes[j] = false;
        }
    }
    int counter{0};
    for (int i = 0; i < n; i++)
    {
        if (primes[i])
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    std::cout << countPrimes(10) << std::endl;
    return 0;
}