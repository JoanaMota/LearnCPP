#include <iostream>
#include <vector>
std::vector<int> countPoints(std::vector<std::vector<int>> &points, std::vector<std::vector<int>> &queries)
{
    // Equation for a circle:
    // (x-xc)^2 + (y-yc)^2 = r^2 (xc,yc) : coordinates of the center
    // so to find a if a point is inside we can use
    // (xpoint-xc)^2 + (ypoint-yc) <= r^2
    std::vector<int> output;
    output.reserve(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int nrPointsInside{0};
        int x{queries[i][0]};
        int y{queries[i][1]};
        int r{queries[i][2]};
        for (int j = 0; j < points.size(); j++)
        {

            int radius = (points[j][0] - x) * (points[j][0] - x) + (points[j][1] - y) * (points[j][1] - y);
            if (radius <= r * r)
            {
                nrPointsInside++;
            }
        }
        output.push_back(nrPointsInside);
    }
    return output;
}
void print(std::vector<int> &nums)
{
    for (int i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<std::vector<int>> points = {{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    std::vector<std::vector<int>> queries = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    std::vector<int> output = countPoints(points, queries);
    print(output);
    return 0;
}