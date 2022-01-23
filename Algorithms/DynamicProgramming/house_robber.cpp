#include <iostream>
#include <vector>

int rob(std::vector<int> &nums)
{
    int rob1{0}, rob2{0};
    for (int i = 0; i < nums.size(); i++)
    {
        // [rob1, rob2, i, i+1, i+2]
        int temp = std::max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int main()
{
    std::vector<int> nums = {1, 3, 1, 3, 100};
    std::cout << rob(nums) << std::endl;
    return 0;
}