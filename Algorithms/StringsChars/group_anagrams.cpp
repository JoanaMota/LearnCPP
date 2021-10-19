#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> output;
    std::unordered_map<std::string, int> anagrams;
    int counter{0};
    for (int strIdx = 0; strIdx < strs.size(); ++strIdx)
    {
        std::string temp = strs[strIdx];
        std::sort(temp.begin(), temp.end());
        if (!anagrams.count(temp))
        {
            anagrams[temp] = counter;
            ++counter;
            output.push_back({strs[strIdx]});
        }
        else
        {
            output[anagrams[temp]].push_back(strs[strIdx]);
        }
    }
    return output;
}

void print(std::vector<std::vector<std::string>> &strs)
{
    for (int i = 0; i < strs.size(); ++i)
    {
        for (int j = 0; j < strs[i].size(); ++j)
        {
            std::cout << strs[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> output = groupAnagrams(input);
    print(output);
    return 0;
}