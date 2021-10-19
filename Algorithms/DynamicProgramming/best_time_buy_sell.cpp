#include <iostream>
#include <vector>
int maxProfit(std::vector<int> &prices)
{
    int profit{0};
    int max{prices[0]};
    int min{prices[0]};

    for (int i = 1; i < prices.size(); i++)
    {
        if (min > prices[i])
        {
            min = prices[i];
            max = prices[i];
        }

        if (max < prices[i])
            max = prices[i];

        if (profit < (max - min))
            profit = max - min;
    }
    return profit;
}

int main()
{
    std::vector<int> prices = {2, 4, 1};
    std::cout << "Profit: " << maxProfit(prices) << std::endl;
    return 0;
}