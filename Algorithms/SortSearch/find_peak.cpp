#include <iostream>
#include <vector>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int findPeakElement(std::vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return 0;
    }
    else if (nums.size() == 2)
    {
        return nums[0] > nums[1] ? 0 : 1;
    }

    int prev = nums[0];
    for (int i = 1; i < nums.size() - 1; ++i)
    {
        if (1 == i && prev > nums[i])
        {
            return 0;
        }

        if (prev < nums[i] && nums[i] > nums[i + 1])
        {
            return i;
        }
        prev = nums[i];
    }
    return nums.size() - 1;
}

int main()
{
    // std::vector<int> nums = {1, 2, 3};
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    // std::vector<int> nums = {6, 5, 4, 3, 2, 3, 2};
    std::cout << findPeakElement(nums) << std::endl;
    return 0;
}