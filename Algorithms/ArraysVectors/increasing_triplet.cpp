#include <iostream>
#include <vector>
#include <bits/stdc++.h>

bool increasingTriplet(std::vector<int> &nums)
{
    int numsSize = nums.size();
    if (numsSize < 3)
    {
        return false;
    }
    int smallest = INT_MAX;
    int middle = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        // int current = nums[i];
        if (nums[i] <= smallest)
        {
            smallest = nums[i];
        }
        else
        {
            if (nums[i] <= middle)
            {
                middle = nums[i];
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // std::vector<int> input = {20, 100, 10, 12, 5, 13};
    std::vector<int> input = {5, 1, 6};
    std::cout << std::boolalpha << increasingTriplet(input) << std::endl;
    return 0;
}