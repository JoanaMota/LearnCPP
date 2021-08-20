#include <iostream>
#include <vector>
#include <unordered_map>

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
    std::cout << std::boolalpha << containsDuplicateO2n(nums) << std::endl;
    return 0;
}