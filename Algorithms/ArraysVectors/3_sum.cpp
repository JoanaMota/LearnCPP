#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> output;
    if (nums.size() < 3)
    {
        return output;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int leftIdx{i + 1}, rightIdx{(int)nums.size() - 1};
        while (leftIdx < rightIdx)
        {
            int threeSum = nums[i] + nums[leftIdx] + nums[rightIdx];
            if (threeSum == 0)
            {
                output.push_back({nums[i], nums[leftIdx], nums[rightIdx]});
                leftIdx++;
                while (nums[leftIdx] == nums[leftIdx - 1] && leftIdx < rightIdx)
                {
                    leftIdx++;
                }
            }
            else if (threeSum > 0)
            {
                rightIdx--;
            }
            else
            {
                leftIdx++;
            }
        }
    }
    return output;
}

void print(std::vector<std::vector<int>> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums[0].size(); ++j)
        {
            std::cout << nums[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // std::vector<int> input = {0, 0, 0, 0};
    std::vector<int> input = {-1, 0, 1, 2, -1, -4};
    // std::vector<int> input = {0};
    std::vector<std::vector<int>> output = threeSum(input);
    print(output);
    return 0;
}