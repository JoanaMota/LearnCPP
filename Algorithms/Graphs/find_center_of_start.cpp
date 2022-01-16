#include <iostream>
#include <vector>
#include <unordered_map>

int findCenterSlower(std::vector<std::vector<int>> &edges)
{
    std::unordered_map<int, int> vertices;
    for (int edge = 0; edge < edges.size(); edge++)
    {
        for (int vertice = 0; vertice < edges[0].size(); vertice++)
        {
            vertices[edges[edge][vertice]]++;
        }
    }
    int maxEdges = edges.size();
    int center{0};
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        if (it->second == maxEdges)
        {
            center = it->first;
            break;
        }
    }
    return center;
}

int findCenter(std::vector<std::vector<int>> &edges)
{
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
    {
        return edges[0][0];
    }
    if (edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1])
    {
        return edges[0][1];
    }
    return 0;
}

int main()
{
    std::vector<std::vector<int>> star = {{1, 2}, {2, 3}, {4, 2}};
    std::cout << "Expect 2: " << findCenter(star) << std::endl;
    return 0;
}