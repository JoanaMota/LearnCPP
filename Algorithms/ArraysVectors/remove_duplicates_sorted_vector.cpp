#include <iostream>
#include <vector>
#include <algorithm>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int back = 0;
    for (int front = 1; front < nums.size(); front++)
    {
        if (nums[front] != nums[back])
        {
            back++;
            nums[back] = nums[front];
        }
    }
    return back + 1;
}

// STD Algorithms
int removeDuplicatesSTD(std::vector<int> &nums)
{
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
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
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    print(nums);
    std::cout << removeDuplicatesSTD(nums) << std::endl;
    print(nums);
    return 0;
}