#include <iostream>
#include <vector>

void rotate(std::vector<int> &nums, int k)
{
    std::vector<int> output(nums.size());
    if (0 == (k % nums.size()))
        return;
    if (k > nums.size())
    {
        k = k % nums.size();
    }
    int index = k;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (index == nums.size())
        {
            index = 0;
        }
        output[index] = nums[i];
        index++;
    }
    nums = output;
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
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    print(nums);
    rotate(nums, 8);
    print(nums);
    return 0;
}