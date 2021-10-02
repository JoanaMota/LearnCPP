#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int> data)
{
    for (int idx = 0; idx < data.size(); idx++)
    {
        std::cout << data[idx] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Original Vector" << std::endl;
    printVector(data);

    std::reverse(data.begin(), data.end());
    std::cout << "Reversed Vector with sdt::reverse" << std::endl;
    printVector(data);

    data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> dataTemp1(data.rbegin(), data.rend());
    data.swap(dataTemp1); // or, call `v = r`
    std::cout << "Reversed Vector with reverse iterator and swap" << std::endl;
    printVector(dataTemp1);

    data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto start = data.begin(), end = std::prev(data.end());
         start < end;
         ++start, --end)
    {
        std::swap(*start, *end);
    }
    std::cout << "Reversed Vector with swap" << std::endl;
    printVector(data);

    data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto mid = data.begin() + data.size() / 2;
    std::transform(data.begin(), mid,
                   data.rbegin(), data.begin(),
                   [](int &x, int &y)
                   {
                       std::swap(x, y);
                       return x;
                   });
    std::cout << "Reversed Vector with transform" << std::endl;
    printVector(data);

    return 0;
}