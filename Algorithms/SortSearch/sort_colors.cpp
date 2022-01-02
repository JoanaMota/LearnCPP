#include <iostream>
#include <vector>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void sortColors(std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return;
    }

    int i{0}, first{0}, last{(int)(nums.size()) - 1};
    while (i <= last)
    {
        if (nums[i] == 0)
        {
            std::swap(nums[first], nums[i]);
            i++;
            first++;
        }
        else if (nums[i] == 1)
        {
            i++;
        }
        else if (nums[i] == 2)
        {
            std::swap(nums[i], nums[last]);
            last--;
        }
        else
        {
            std::cout << "ERROR" << std::endl;
        }
    }
}

int main()
{
    std::vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    print(colors);
    return 0;
}