#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono> // std::chrono::system_clock

void eraseVal(std::unordered_map<int, int> &map, int val)
{
    auto it = map.find(val);
    if (it != map.end())
    {
        it->second--;
        if (0 == it->second)
        {
            map.erase(it);
        }
    }
}

// This option is not faster in overall but does operation 3(check if frequency exists) in constant time and the overall time complexity is O(n)
std::vector<int> freqQuery(std::vector<std::vector<int>> &queries)
{
    std::unordered_map<int, int> data;
    std::unordered_map<int, int> frequencies;
    std::vector<int> output;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int operation = queries[i][0];
        int val = queries[i][1];
        if (1 == operation)
        {
            eraseVal(frequencies, data[val]); //100
            data[val]++;
            frequencies[data[val]]++;
        }
        else if (2 == operation)
        {
            auto it = data.find(val);
            if (it != data.end())
            {
                eraseVal(frequencies, data[val]);
                it->second--;
                frequencies[it->second]++;
                if (0 == it->second)
                {
                    data.erase(it);
                }
            }
        }
        else if (3 == operation)
        {
            if (frequencies.count(val))
            {
                output.push_back(1);
            }
            else
            {
                output.push_back(0);
            }
        }
    }
    return output;
}

// This option at the worst case can be O(n^2) but for smaller amounts of data it is faster
std::vector<int> freqQueryOn2(std::vector<std::vector<int>> queries)
{
    std::unordered_map<int, int> data;
    std::vector<int> output;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int operation = queries[i][0];
        int val = queries[i][1];
        if (1 == operation)
        {
            data[val]++;
        }
        else if (2 == operation)
        {
            auto it = data.find(val);
            if (it != data.end())
            {
                it->second--;
                if (0 == it->second)
                {
                    data.erase(it);
                }
            }
        }
        else if (3 == operation)
        {
            int present{0};
            for (const auto &it : data)
            {
                if (val == it.second)
                {
                    present = 1;
                    break;
                }
            }
            output.push_back(present);
        }
    }
    return output;
}

int main()
{
    std::vector<std::vector<int>> queries = {{1, 1}, {2, 2}, {3, 2}, {1, 1}, {1, 1}, {2, 1}, {3, 2}};
    auto begin = std::chrono::high_resolution_clock::now();
    std::vector<int> output = freqQuery(queries);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << " Time: " << elapsed.count() << " nanoseconds" << std::endl;
    for (int num : output)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}