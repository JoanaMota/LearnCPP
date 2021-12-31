#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void print(std::vector<int> vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

long largestRectangle(std::vector<int> h)
{
    long area{0}, maxArea{0};
    int top, i;
    std::stack<int> temp;
    temp.push(0);
    for (i = 1; i < h.size();)
    {
        if (temp.empty() || h[temp.top()] < h[i])
        {
            temp.push(i);
            i++;
        }
        else
        {
            top = temp.top();
            temp.pop();

            // Calculate Area
            if (temp.empty())
            {
                area = h[top] * i;
            }
            else
            {
                area = h[top] * (i - temp.top() - 1);
            }

            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }

    while (!temp.empty())
    {
        top = temp.top();
        temp.pop();

        // Calculate Area
        if (temp.empty())
        {
            area = h[top] * i;
        }
        else
        {
            area = h[top] * (i - temp.top() - 1);
        }

        if (area > maxArea)
        {
            maxArea = area;
        }
    }

    return maxArea;
}
int main()
{
    // std::vector<int> input = {8979, 4570, 6436, 5083, 7780, 3269, 5400, 7579, 2324, 2116};
    std::vector<int> input = {3, 2, 3};
    std::cout << largestRectangle(input) << std::endl;
    return 0;
}