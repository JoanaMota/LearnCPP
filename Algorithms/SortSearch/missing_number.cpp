#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int missingNumber2On2(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    // std::cout << nums[0] << std::endl;
    int n = nums.size();
    int output{n};
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            output = i;
            break;
        }
    }
    return output;
}
int missingNumberOn(std::vector<int> &nums)
{
    int sumExpected{0}, realSum{0}, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sumExpected += i;
        realSum += nums[i];
    }
    sumExpected += n;
    std::cout << sumExpected << " " << realSum << std::endl;
    return sumExpected - realSum;
}

int missingNumberOtherSolution(std::vector<int> &nums)
{
    int n = nums.size();
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= nums[i];
    return total;
}

int main()
{
    std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "Missing number: " << missingNumberOn(nums) << std::endl;
    return 0;
}