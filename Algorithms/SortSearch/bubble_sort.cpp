#include <iostream>
#include <vector>

void countSwaps(std::vector<int> &a)
{
    int nrSwaps{0};
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size() - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                nrSwaps++;
            }
        }
    }
    std::cout << "Array is sorted in " << nrSwaps << " swaps" << std::endl;
    std::cout << "First Element " << a[0] << std::endl;
    std::cout << "Last Element " << a[a.size() - 1] << std::endl;
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
    std::vector<int> a = {6, 4, 1};
    countSwaps(a);
    print(a);

    return 0;
}