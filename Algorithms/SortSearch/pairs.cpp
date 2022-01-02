#include <iostream>
#include <vector>
#include <unordered_set>

int pairs(int k, std::vector<int> arr)
{
    std::unordered_set<int> numbers;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= k)
        {
            numbers.insert(arr[i] - k);
        }
        // numbers.insert(arr[i] + 2); // in case it was also plus
    }
    int nrPairs{0};
    for (int i = 0; i < arr.size(); i++)
    {
        if (numbers.count(arr[i]))
        {
            nrPairs++;
        }
    }
    return nrPairs;
}

int main()
{
    std::vector<int> arr = {1, 5, 3, 4, 2};
    std::cout << pairs(2, arr) << std::endl;
    return 0;
}