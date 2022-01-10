#include <iostream>
#include <vector>
#include <math.h>

bool canJump(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    int currMax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (currMax >= i)
        {
            currMax = std::max(currMax, i + nums[i]);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> nums = {1, 0, 1, 0};
    std::cout << std::boolalpha << canJump(nums) << std::endl;
    return 0;
}