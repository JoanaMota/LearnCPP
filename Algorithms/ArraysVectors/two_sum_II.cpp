#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::unordered_map<int, int> subNumbers;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (subNumbers.find(target - numbers[i]) != subNumbers.end())
        {
            return {subNumbers[target - numbers[i]] + 1, i + 1};
        }
        subNumbers[numbers[i]] = i;
    }
    return {};
}
std::vector<int> twoSum2Pointers(std::vector<int> &numbers, int target)
{
    int left{0}, right{(int)numbers.size() - 1};
    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
        {
            return {left + 1, right + 1};
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}
int main()
{
    std::vector<int> numbers = {2, 7, 11, 15};
    std::vector<int> output = twoSum2Pointers(numbers, 9);
    for (int i : output)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}