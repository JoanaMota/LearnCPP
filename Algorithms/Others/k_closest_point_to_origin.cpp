#include <iostream>
#include <vector>
#include <map>
#include <math.h>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
{
    if (points.size() == k)
    {
        return points;
    }

    std::multimap<double, std::pair<int, int>> distances;
    for (int i = 0; i < points.size(); i++)
    {
        int x = std::abs(points[i][0]);
        int y = std::abs(points[i][1]);
        double distance = std::sqrt(x * x + y * y);
        distances.insert(std::pair<double, std::pair<int, int>>(distance, {points[i][0], points[i][1]}));
    }
    std::vector<std::vector<int>> output(k, std::vector<int>(2, 0));
    std::multimap<double, std::pair<int, int>>::iterator it = distances.begin();
    for (int i = 0; i < k; i++)
    {
        output[i][0] = it->second.first;
        output[i][1] = it->second.second;
        it++;
    }
    return output;
}

void print(std::vector<std::vector<int>> &points)
{
    for (int i = 0; i < points.size(); i++)
    {
        std::cout << points[i][0] << " " << points[i][1] << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}, {2, -2}};
    std::vector<std::vector<int>> output = kClosest(points, 2);
    print(output);
    return 0;
}