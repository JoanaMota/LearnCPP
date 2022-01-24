#include <iostream>
#include <vector>
#include <chrono>

void selectionSort(std::vector<int> &a)
{
    int nrSwaps{0};
    for (int step = 0; step < (a.size() - 1); ++step)
    {
        int minIdx{step};
        for (int i = minIdx + 1; i < a.size(); ++i)
        {
            if (a[minIdx] > a[i])
            {
                minIdx = i;
            }
        }
        if (minIdx != step)
        {
            std::swap(a[minIdx], a[step]);
        }
        nrSwaps++;
    }
    std::cout << "Array is sorted in " << nrSwaps << " swaps" << std::endl;
}

void print(std::vector<int> a)
{
    for (int el : a)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> a = {6, -11, 4, 1, -5, 20};
    print(a);

    auto begin = std::chrono::high_resolution_clock::now();
    selectionSort(a);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Bubble Sort Time: " << elapsed.count() << " nanoseconds" << std::endl;

    print(a);

    return 0;
}