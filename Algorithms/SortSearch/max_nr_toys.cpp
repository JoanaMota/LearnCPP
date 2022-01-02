#include <iostream>
#include <vector>
#include <algorithm>

int maximumToys(std::vector<int> prices, int k)
{
    std::sort(prices.begin(), prices.end());
    int sum{0};
    int i{0};
    for (; i < prices.size(); i++)
    {
        sum += prices[i];
        if (sum > k)
        {
            return i;
        }
    }
    return i;
}

int main()
{
    std::vector<int> input = {1, 12, 5, 111, 200, 1000, 10};
    std::cout << maximumToys(input, 50) << std::endl;
    return 0;
}