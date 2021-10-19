#include <iostream>
#include <vector>
#include <unordered_map>
int majorityElement(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    std::unordered_map<int, int> mNums;
    int nrElements{0};
    int major{0};
    for (int i = 0; i < nums.size(); i++)
    {
        if (mNums.count(nums[i]))
        {
            mNums[nums[i]]++;
            if (nrElements < mNums[nums[i]])
            {
                nrElements = mNums[nums[i]];
                major = nums[i];
            }
        }
        else
        {
            mNums[nums[i]] = 0;
        }
    }
    return major;
}
int main()
{
    std::vector<int> input = {2, 2, 1, 1, 1, 2, 2};
    std::cout << majorityElement(input) << std::endl;
    return 0;
}