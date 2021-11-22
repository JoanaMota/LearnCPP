#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

void print(std::vector<std::string> &input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}
std::unordered_map<char, std::vector<char>> possibilities;

void combine(int level, std::string digits, std::vector<std::string> &options, std::string q)
{
    // print(options);
    if (level == digits.size())
    {
        options.push_back(q);
        return;
    }
    for (auto x : possibilities[digits[level]])
    {
        combine(level + 1, digits, options, q + x);
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    if (digits.size() == 0)
    {
        return {};
    }
    std::vector<std::string> options;

    possibilities['2'] = {'a', 'b', 'c'};
    possibilities['3'] = {'d', 'e', 'f'};
    possibilities['4'] = {'g', 'h', 'i'};
    possibilities['5'] = {'j', 'k', 'l'};
    possibilities['6'] = {'m', 'n', 'o'};
    possibilities['7'] = {'p', 'q', 'r', 's'};
    possibilities['8'] = {'t', 'u', 'v'};
    possibilities['9'] = {'w', 'x', 'y', 'z'};

    combine(0, digits, options, "");
    return options;
}

int main()
{
    std::string input = "23";
    std::vector<std::string> output = letterCombinations(input);
    print(output);
    return 0;
}