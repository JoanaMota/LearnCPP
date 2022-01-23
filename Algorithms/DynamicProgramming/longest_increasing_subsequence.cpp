#include <iostream>
#include <vector>
int lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> longest;
    longest.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {

        if (nums[i] > longest.back())
        {
            longest.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(longest.begin(), longest.end(), nums[i]) - longest.begin();
            longest[idx] = nums[i];
        }
    }
    return longest.size();
}
int main()
{
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // std::vector<int> nums = {4, 10, 4, 3, 8, 9};
    std::cout << lengthOfLIS(nums) << std::endl;
    return 0;
}