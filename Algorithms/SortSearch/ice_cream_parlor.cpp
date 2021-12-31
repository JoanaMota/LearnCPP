#include <iostream>
#include <vector>
#include <unordered_map>

void whatFlavors(std::vector<int> cost, int money)
{
    std::unordered_map<int, int> costMap;
    for (int i = 0; i < cost.size(); ++i)
    {
        if (costMap.find(cost[i]) != costMap.end())
        {
            std::cout << costMap[cost[i]] << " " << i + 1 << std::endl;
            return;
        }
        costMap[money - cost[i]] = i + 1;
    }
}

int main()
{
    std::vector<int> cost = {2, 1, 3, 5, 6};
    whatFlavors(cost, 5);
    return 0;
}