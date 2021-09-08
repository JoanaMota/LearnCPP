#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        std::cout << i << std::endl;
        if (digits[i] == 9 && i == 0)
        {
            digits[i] = 1;
            digits.push_back(0);
        }
        else if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i] = digits[i] + 1;
            return digits;
        }
    }
    return digits;
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
    std::vector<int> nums1 = {9, 9, 9};
    print(nums1);
    std::vector<int> numsOut = plusOne(nums1);
    print(numsOut);
    return 0;
}