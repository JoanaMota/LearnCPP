#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int maxMin(int k, std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    print(arr);
    int output = arr[arr.size() - 1] - arr[0];
    int temp;
    for (int i = 0; i < arr.size() - k + 1; ++i)
    {
        temp = arr[i + k - 1] - arr[i];
        if (temp < output)
        {
            output = temp;
        }
    }
    return output;
}

int main()
{
    // std::vector<int> arr = {4504, 1520, 5857, 4094, 4157, 3902, 822, 6643, 2422, 7288, 8245, 9948, 2822, 1784, 7802, 3142, 9739, 5629, 5413, 7232};
    std::vector<int> arr = {100, 200, 300, 350, 400, 401, 402};
    std::cout << maxMin(3, arr) << std::endl;
    return 0;
}