#include <iostream>
#include <vector>
#include <algorithm>

int combinationSum4(std::vector<int> &nums, int target)
{
    if (0 == nums.size())
    {
        return 0;
    }
    if (1 == nums.size())
    {
        if (nums[0] == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // For example:
    // nums = {1,2,3}
    // target = 4
    // for a terget of 0 -> 1
    // for a terget of 1 -> target of 0
    // for a terget of 2 -> target of 0 + target of 1
    // for a terget of 3 -> target of 0 + target of 1 + target of 2
    // for a terget of 4 -> target of 0 + target of 1 + target of 2 + target of 3
    // So...
    // memo[0] = 1;
    // memo[4] = memo[4-1] + memo[4-2] + memo[4-3];

    std::vector<uint32_t> memo(target + 1, 0);
    memo[0] = 1;
    for (int i = 1; i < memo.size(); i++)
    {
        for (int num : nums)
        {
            if (num <= i)
            {
                memo[i] += memo[i - num];
            }
        }
    }
    return memo[target];
}

int main()
{
    std::vector<int> nums = {1, 2, 3};
    std::cout << combinationSum4(nums, 4) << std::endl;
    return 0;
}