#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> lexicalOrder(int n)
{
    std::vector<std::string> numsStr(n);
    for (int i = 1; i < n + 1; i++)
    {
        numsStr[i - 1] = std::to_string(i);
    }
    std::sort(numsStr.begin(), numsStr.end());

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = std::stoi(numsStr[i]);
    }
    return nums;
}

void helper(int cur, int n, std::vector<int> &result)
{
    if (cur > n)
        return;
    result.push_back(cur);
    for (int i = 0; i <= 9; ++i)
    {
        if (cur * 10 + i <= n)
            helper(cur * 10 + i, n, result);
        else
            break;
    }
}
std::vector<int> lexicalOrderFaster(int n)
{
    std::vector<int> result;
    result.reserve(n);
    for (int i = 1; i <= 9; ++i)
    {
        helper(i, n, result);
    }
    return result;
}

int main()
{
    std::vector<int> out = lexicalOrderFaster(27);
    for (int i : out)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}