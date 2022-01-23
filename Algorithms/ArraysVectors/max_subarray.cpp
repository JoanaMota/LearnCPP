#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int maxSubArray(std::vector<int> &nums)
{
    int max = 0;
    int maxEnd = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        max = max + nums[i];
        if (max > maxEnd)
            maxEnd = max;
        if (max < 0)
            max = 0;
    }
    return maxEnd;
}

int main()
{
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubArray(nums) << std::endl;
    return 0;
}