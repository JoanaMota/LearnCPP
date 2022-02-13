#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}
int longestConsecutive(std::vector<int> &nums)
{
    if (0 == nums.size())
    {
        return 0;
    }
    if (1 == nums.size())
    {
        return 1;
    }

    std::sort(nums.begin(), nums.end());
    print(nums);
    int ans{0}, current{1};
    int previous{nums[0]};
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] > previous + 1)
        {
            current = 1;
        }
        else if (nums[i] != previous)
        {
            current++;
        }
        ans = std::max(ans, current);
        previous = nums[i];
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {1, 2, 0, 1};
    std::cout << longestConsecutive(nums) << std::endl;
    return 0;
}