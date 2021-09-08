#include <iostream>
#include <vector>

int singleNumber(std::vector<int> &nums)
{
    int single = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        single = single ^ nums[i];
    }
    return single;
}

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums = {6, 6, 1, 1, 4, 2, 2, 3, 3};
    print(nums);
    std::cout << singleNumber(nums) << std::endl;
    print(nums);
    return 0;
}