#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
{
    std::vector<std::vector<int>> output;
    for (size_t i{0}; i < intervals.size(); i++)
    {
        if (newInterval[0] > intervals[i][1])
        {
            output.push_back(intervals[i]);
        }
        else if (newInterval[1] < intervals[i][0])
        {
            output.push_back(newInterval);
            newInterval = intervals[i];
        }
        else
        {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    output.push_back(newInterval);
    return output;
}

void print(std::vector<std::vector<int>> &intervals)
{
    for (size_t i = 0; i < intervals.size(); i++)
    {
        std::cout << intervals[i][0] << " " << intervals[i][1] << " | ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> newIntervals = {4, 7};
    std::vector<std::vector<int>> output = insert(intervals, newIntervals);
    print(output);
    return 0;
}