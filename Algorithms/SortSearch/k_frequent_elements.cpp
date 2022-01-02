#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

void print(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}
void print(std::priority_queue<std::pair<int, int>> pqueue)
{
    while (!pqueue.empty())
    {
        std::cout << pqueue.top().first << " " << pqueue.top().second << std::endl;
        pqueue.pop();
    }
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    if (nums.size() == k)
    {
        return nums;
    }
    std::unordered_map<int, int> singleNums;

    for (int i = 0; i < nums.size(); i++)
    {
        singleNums[nums[i]]++;
    }

    std::priority_queue<std::pair<int, int>> pqueue;
    for (auto i : singleNums)
    {
        pqueue.push({i.second, i.first});
    }
    print(pqueue);

    std::vector<int> output;
    output.resize(k);
    for (int i = 0; i < k; i++)
    {
        output[i] = pqueue.top().second;
        pqueue.pop();
    }
    return output;
}

int main()
{
    std::vector<int> input = {1, 1, 1, 2, 2, 3};
    std::vector<int> output = topKFrequent(input, 2);
    print(output);
    return 0;
}