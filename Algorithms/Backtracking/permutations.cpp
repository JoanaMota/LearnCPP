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

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> output{};
    int options = nrOptions(nums.size());
    output.resize(options);

    int idx = 0;
    std::sort(nums.begin(), nums.end());
    do
    {
        output[idx] = nums;
        idx++;
    } while (std::next_permutation(nums.begin(), nums.end()));

    return output;
}
int main()
{
    std::vector<int> nums = {0, 1};
    std::vector<std::vector<int>> output = permute(nums);
    print(output);
    return 0;
}