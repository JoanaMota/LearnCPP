#include <iostream>
#include <vector>

int findMinLinearSearch(std::vector<int> &nums)
{
    int min{nums[0]};
    for (int num : nums)
    {
        if (min > num)
            min = num;
    }
    return min;
}
int findMinBinarySearch(std::vector<int> &nums)
{
    int itLeft{0};
    int itRight{(int)nums.size() - 1};
    int itMid;
    if (1 == nums.size() || nums[itRight] > nums[0])
    {
        return nums[0];
    }
    while (itLeft <= itRight)
    {
        itMid = itLeft + (int)((itRight - itLeft) / 2);
        // if the itMid element is greater than its next element then itMid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        if (nums[itMid] > nums[itMid + 1])
        {
            return nums[itMid + 1];
        }

        // if the itMid element is lesser than its previous element then itMid element is the smallest
        if (nums[itMid - 1] > nums[itMid])
        {
            return nums[itMid];
        }
        if (nums[itMid] > nums[itLeft])
        {
            itLeft = itMid;
        }
        else
        {
            itRight = itMid;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = {3, 4, 5, 1, 2};
    std::cout << findMinBinarySearch(nums) << std::endl;
    return 0;
}