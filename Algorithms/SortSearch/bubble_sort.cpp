#include <iostream>
#include <vector>
#include <chrono>

void bubbleSort(std::vector<int> &a)
{
    int nrSwaps{0};
    for (int step = 0; step < (a.size() - 1); ++step)
    {
        bool swapped{false};
        for (int i = 0; i < (a.size() - step - 1); ++i)
        {
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                nrSwaps++;
                swapped = true;
            }
        }
        // no swapping means the array is already sorted
        // so no need of further comparison
        if (!swapped)
        {
            break;
        }
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
    bubbleSort(a);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Bubble Sort Time: " << elapsed.count() << " nanoseconds" << std::endl;

    print(a);

    return 0;
}