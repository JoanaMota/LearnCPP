#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string output = "";
    bool equal = true;
    for (int letter = 0; letter < strs[0].size(); ++letter)
    {
        for (int i = 1; i < strs.size(); ++i)
        {
            if (letter == strs[i - 1].size() || letter == strs[i].size() || strs[i][letter] != strs[i - 1][letter])
            {
                equal = false;
                break;
            }
        }
        if (!equal)
        {
            break;
        }

        output += strs[0][letter];
    }
    return output;
}

int main()
{
    // std::vector<std::string> words = {"ab", "a"};
    std::vector<std::string> words = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(words) << std::endl;
    return 0;
}