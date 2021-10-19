#include <iostream>
#include <vector>
#include <map>
std::vector<int> twoSumFaster(std::vector<int> &nums, int target)
{
    std::map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> output;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                output.push_back(i);
                output.push_back(j);
                return output;
            }
        }
    }
    return output;
}
int main()
{
    std::vector<int> input = {3, 2, 4};
    std::vector<int> output = twoSumFaster(input, 6);
    for (int el : output)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}