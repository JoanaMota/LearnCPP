#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<std::vector<int>> &input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        for (int f = 0; f < input[i].size(); f++)
        {
            std::cout << input[i][f] << " ";
        }
        std::cout << " | ";
    }
    std::cout << std::endl;
}
void print(std::vector<int> &input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

int nrOptions(int size)
{
    int options{1};
    for (int i = size; i > 0; --i)
    {
        options *= i;
    }
    return options;
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> output;
    std::vector<int> temp;
    output.push_back({});
    for (int i = 0; i < nums.size(); i++)
    {
        output.push_back({nums[i]});
        int size = output.size();
        for (int f = 1; f < size - 1; f++)
        {
            std::cout << "Here" << std::endl;
            temp = output[f];
            print(temp);
            temp.push_back(nums[i]);
            output.push_back(temp);
        }
    }
    return output;
}
int main()
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> output = subsets(nums);
    print(output);
    return 0;
}