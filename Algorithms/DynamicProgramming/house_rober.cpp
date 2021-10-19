#include <iostream>
#include <vector>

int rob(std::vector<int> &nums)
{
    int max1{0}, max2{0};
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = std::max(max1, max2 + nums[i]);
        max2 = max1;
        max1 = temp;
    }
    return std::max(max1, max2);
}

int main()
{
    std::vector<int> nums = {1, 3, 1, 3, 100};
    std::cout << rob(nums) << std::endl;
    return 0;
}