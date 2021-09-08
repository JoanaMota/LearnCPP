#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> output;
    std::unordered_map<int, int> mapNums1;
    for (int num : nums1)
    {
        mapNums1[num]++;
    }
    for (int i = 0; i < nums2.size(); ++i)
    {
        if (mapNums1[nums2[i]] > 0)
        {
            output.push_back(nums2[i]);
            int temp = mapNums1[nums2[i]];
            mapNums1[nums2[i]] = temp - 1;
        }
    }
    return output;
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
    std::vector<int> nums1 = {4, 9, 5};
    std::vector<int> nums2 = {9, 4, 9, 8, 4};
    print(nums1);
    print(nums2);
    std::vector<int> numsOut = intersect(nums1, nums2);
    print(numsOut);
    return 0;
}