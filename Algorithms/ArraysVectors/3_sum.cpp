#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> output;
    if (nums.size() < 3)
    {
        return output;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if ((i + 1) == nums.size())
        {
            break;
        }

        if ((i - 1) >= 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int low = i + 1, high = nums.size() - 1; low < high;)
        {

            int sum = nums[i] + nums[low] + nums[high];
            if (sum < 0)
                low++;
            else if (sum > 0)
                high--;
            else
            {
                std::vector<int> temp = {nums[i], nums[low], nums[high]};
                output.push_back(temp);
                ++low;
                while (low < high && nums[low - 1] == nums[low])
                    ++low;
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
    std::vector<int> input = {-1, 0, 1, 2, -1, -4};
    // std::vector<int> input = {0};
    std::vector<std::vector<int>> output = threeSum(input);
    print(output);
    return 0;
}