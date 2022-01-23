#include <iostream>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int climbStairsFib(int s)
{
    return fib(s + 1);
}
int climbStairsCache(int n)
{
    int dp[50];

    dp[n] = 1;
    dp[n - 1] = 2;

    for (int i = n - 2; i >= 1; i--)
    {
        dp[i] = dp[i + 1] + dp[i + 2];
    }

    return dp[1];
}
int climbStairs(int n)
{
    int prev{2}, prevprev{1}, current{0};
    if (1 == n)
    {
        return 1;
    }
    else if (2 == n)
    {
        return 2;
    }

    for (int i = 2; i < n; i++)
    {
        current = prev + prevprev;
        prevprev = prev;
        prev = current;
    }
    return current;
}

int main()
{
    std::cout << climbStairs(4) << std::endl;
    return 0;
}