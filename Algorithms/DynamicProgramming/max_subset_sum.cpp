#include <iostream>
#include <vector>
#include <algorithm>

int maxSubsetSum(std::vector<int> arr)
{
    int prevprev = 0;
    int prev = std::max(0, arr[0]);
    int sumsMax{0};
    int max{0};
    for (int i = 1; i < arr.size(); i++)
    {
        max = std::max(prevprev, std::max(prev, prevprev + arr[i]));
        prevprev = prev;
        prev = max;
    }
    return std::max(prev, prevprev);
}

int maxSubsetSumMemoize(std::vector<int> arr)
{
    int dp[100005];
    dp[0] = std::max(0, arr[0]);
    if (arr.size() == 1)
        return dp[0];
    for (int i = 1; i < arr.size(); i++)
    {
        dp[i] = std::max(dp[i - 2], std::max(dp[i - 1], dp[i - 2] + arr[i]));
    }
    int n = arr.size();
    return std::max(dp[n - 1], dp[n - 2]);
}

int main()
{
    std::vector<int> input = {2, 1, 5, 8, 4};
    std::cout << maxSubsetSum(input) << std::endl;
    return 0;
}