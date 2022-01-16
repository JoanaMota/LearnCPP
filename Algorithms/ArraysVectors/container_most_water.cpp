#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height)
{
    int max{0};
    int itRight{(int)height.size() - 1};
    int itLeft{0};
    while (itRight != itLeft)
    {
        int area = std::min(height[itLeft], height[itRight]) * (itRight - itLeft);
        if (max < area)
        {
            max = area;
        }
        if (height[itLeft] < height[itRight])
        {
            itLeft++;
        }
        else
        {
            itRight--;
        }
    }
    return max;
}

int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << maxArea(height) << std::endl;
    return 0;
}