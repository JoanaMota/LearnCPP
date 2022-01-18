#include <iostream>
#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
{
    std::sort(intervals.begin(), intervals.end());

    int end{intervals[0][1]};
    int counter{0};
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end)
        {
            counter++;
            end = std::min(intervals[i][1], end);
        }
        else
        {
            end = intervals[i][1];
        }
    }
    return counter;
}

int main()
{
    std::vector<std::vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    std::cout << eraseOverlapIntervals(intervals) << std::endl;
    return 0;
}