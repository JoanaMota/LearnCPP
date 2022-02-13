#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // std::chrono::system_clock

int minimumAbsoluteDifferenceOn2(std::vector<int> &arr)
{
    int minAbsDif{INT32_MAX};
    int absDif{0};
    int first{0};
    for (int i = 0; i < arr.size(); ++i)
    {
        first = arr[i];
        for (int j = i + 1; j < arr.size(); ++j)
        {
            absDif = std::abs(first - arr[j]);
            minAbsDif = std::min(minAbsDif, absDif);
        }
    }
    return minAbsDif;
}
int minimumAbsoluteDifferenceFasterOnlongn(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int minAbsDif{INT32_MAX};
    int absDif{0};
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        absDif = std::abs(arr[i] - arr[i + 1]);
        minAbsDif = std::min(minAbsDif, absDif);
    }
    return minAbsDif;
}

int main()
{
    std::vector<int> arr = {3, -7, 0};

    auto begin = std::chrono::high_resolution_clock::now();
    int output = minimumAbsoluteDifferenceFasterOnlongn(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "minimumAbsoluteDifferenceFasterOnlongn: " << output << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    auto begin2 = std::chrono::high_resolution_clock::now();
    int output2 = minimumAbsoluteDifferenceOn2(arr);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    std::cout << "minimumAbsoluteDifferenceOn2: " << output2 << " Time: " << elapsed2.count() << " nanoseconds" << std::endl;
    return 0;
}