#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool containsDuplicateOn2(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}
bool containsDuplicateO2n(std::vector<int> &nums)
{
    std::unordered_map<int, int> equals;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (equals[nums[i]] != 0)
            return true;

        equals[nums[i]] = 1;
    }
    return false;
}
bool containsDuplicateO2nSet(std::vector<int> &nums)
{
    std::unordered_set<int> equals;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (equals.count(nums[i]))
            return true;

        equals.insert(nums[i]);
    }
    return false;
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
    std::vector<int> nums = {1, 2, 3, 4};
    print(nums);
    std::cout << std::boolalpha << containsDuplicateO2nSet(nums) << std::endl;
    return 0;
}