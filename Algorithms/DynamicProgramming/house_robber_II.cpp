#include <iostream>
#include <vector>

int rob(std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int prevprevHouse{0}, prevHouse{0};
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int temp = std::max(prevprevHouse + nums[i], prevHouse);

        prevprevHouse = prevHouse;
        prevHouse = temp;
    }
    int ans = prevHouse;
    prevprevHouse = 0;
    prevHouse = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = std::max(prevprevHouse + nums[i], prevHouse);

        prevprevHouse = prevHouse;
        prevHouse = temp;
    }
    return std::max(prevHouse, ans);
}

int main()
{
    std::vector<int> nums = {1, 2, 1, 1};
    std::cout << rob(nums) << std::endl;
    return 0;
}