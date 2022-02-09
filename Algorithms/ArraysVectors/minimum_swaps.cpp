#include <iostream>
#include <vector>

int minimumSwaps(std::vector<int> &arr)
{
    int nrSwaps{0};
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != i + 1)
        {
            int j = i + 1;
            for (; j < arr.size(); ++j)
            {
                if (arr[j] == i + 1)
                {
                    break;
                }
            }
            std::swap(arr[i], arr[j]);
            nrSwaps++;
        }
    }
    return nrSwaps;
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 2, 4, 6, 7};
    std::cout << minimumSwaps(arr) << std::endl;
    return 0;
}