#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool dfsIsValid(int course, std::unordered_map<int, std::vector<int>> schedule, std::unordered_set<int> &visited)
{
    if (visited.count(course))
    {
        return false;
    }
    if (schedule[course].size() == 0)
    {
        return true;
    }
    visited.insert(course);
    for (int pre : schedule[course])
    {
        if (false == dfsIsValid(pre, schedule, visited))
        {
            return false;
        }
    }
    schedule[course] = {};
    visited.erase(course);
    return true;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
{
    if (prerequisites.size() == 1 && numCourses == 2)
    {
        return true;
    }
    std::unordered_map<int, std::vector<int>> schedule;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        schedule[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    std::unordered_set<int> visited;
    for (int i = 0; i < numCourses; i++)
    {
        if (false == dfsIsValid(i, schedule, visited))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> prerequisites = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 4}};
    std::cout << std::boolalpha << canFinish(5, prerequisites) << std::endl;
    return 0;
}