#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    if (1 == intervals.size())
    {
        return intervals;
    }
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> output;
    int i;

    for (i = 0; i < intervals.size() - 1; i++)
    {
        if (intervals[i][1] < intervals[i + 1][0])
        {
            output.push_back(intervals[i]);
        }
        else
        {
            intervals[i + 1][0] = intervals[i][0];
            if (intervals[i + 1][1] <= intervals[i][1])
            {
                intervals[i + 1][1] = intervals[i][1];
            }
        }
    }

    output.push_back(intervals[i]);
    return output;
}

void print(std::vector<std::vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        std::cout << matrix[row][0] << " " << matrix[row][1] << " , ";
    }
    std::cout << std::endl;
}

int main()
{
    // std::vector<std::vector<int>> input = {{1, 3}, {2, 6}};
    std::vector<std::vector<int>> input = {{1, 4}, {0, 2}, {3, 5}};
    std::vector<std::vector<int>> output = merge(input);
    print(output);
    return 0;
}