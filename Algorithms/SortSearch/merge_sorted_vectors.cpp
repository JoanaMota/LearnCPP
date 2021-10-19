#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int it1 = m - 1;
    int it2 = n - 1;
    int itFull = nums1.size() - 1;
    while (it1 >= 0 && it2 >= 0)
    {
        if (nums2[it2] < nums1[it1])
        {
            nums1[itFull] = nums1[it1];
            it1--;
        }
        else
        {
            nums1[itFull] = nums2[it2];
            it2--;
        }
        itFull--;
    }
    while (it2 >= 0)
    {
        nums1[itFull] = nums2[it2];
        itFull--;
        it2--;
    }
}

void mergeSTL(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{

    for (int i = m; i < n + m; ++i)
    {
        nums1[i] = nums2[i - m];
    }

    std::sort(nums1.begin(), nums1.end());
}

int main()
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;
    print(nums1);
    print(nums2);
    std::cout << "Doing Merge" << std::endl;
    merge(nums1, m, nums2, n);
    std::cout << "Merged" << std::endl;
    print(nums1);
    return 0;
}