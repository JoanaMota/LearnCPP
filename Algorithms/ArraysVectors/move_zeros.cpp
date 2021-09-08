#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroesBetterMemory(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (0 == nums[i])
        {
            int j = i;
            for (; 0 == nums[j]; j++)
            {
                if ((nums.size() - 1) == j)
                {
                    return;
                }
            }
            nums[i] = nums[j];
            nums[j] = 0;
        }
    }
}
void moveZeroesBetterRuntime(std::vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (0 != nums[i]) //When we encounter a non-zero element, we swap.
        {
            // Swap
            int temp = nums[count];
            nums[count] = nums[i];
            nums[i] = temp;
            count++; //Increment the count of non-zero, this will be the index next to the swapped element.
        }
    }
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
    // std::vector<int> nums1 = {2, 1, 4, 12, 8, 2, 0, 3, 5};
    std::vector<int> nums1 = {0, 0, 0, 0};
    print(nums1);
    moveZeroesBetterRuntime(nums1);
    print(nums1);
    return 0;
}