#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int coinChangeHelper(std::vector<int> &coins, int amount, std::vector<int> &cache)
{
    if (amount < 0)
        return -1;
    if (amount == 0)
        return 0;
    if (cache[amount - 1] != 0)
        return cache[amount - 1];
    int min = INT_MAX;
    for (int coin : coins)
    {
        int res = coinChangeHelper(coins, amount - coin, cache);
        if (res >= 0 && res < min)
            min = 1 + res;
    }
    cache[amount - 1] = (min == INT_MAX) ? -1 : min;
    return cache[amount - 1];
}
int coinChange(std::vector<int> &coins, int amount)
{
    std::vector<int> cache(amount, 0);
    return coinChangeHelper(coins, amount, cache);
}

int main()
{
    std::vector<int> coins = {1, 2, 5};
    std::cout << coinChange(coins, 11) << std::endl;
    return 0;
}