#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int findKthLargest(std::vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main()
{
    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << findKthLargest(nums, 4) << std::endl;
    return 0;
}