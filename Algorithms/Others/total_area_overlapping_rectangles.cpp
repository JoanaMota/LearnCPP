#include <iostream>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int areaA = (ax2 - ax1) * (ay2 - ay1);
    int areaB = (bx2 - bx1) * (by2 - by1);

    int overlappingArea{0};
    if (0 == areaA || 0 == areaB || ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1)
    {
        overlappingArea = 0;
    }
    else
    {
        // Length - X
        int length{std::min(bx2, ax2) - std::max(bx1, ax1)};
        // Height - Y
        int height{std::min(by2, ay2) - std::max(by1, ay1)};
        overlappingArea = length * height;
    }
    return areaA + areaB - overlappingArea;
}

int main()
{
    std::cout << computeArea(0, 0, 0, 0, -1, -1, 1, 1) << std::endl;
    return 0;
}