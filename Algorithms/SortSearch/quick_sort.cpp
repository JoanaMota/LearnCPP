#include <iostream>
#include <vector>
#include <chrono>

// function to rearrange array (find the partition point)
int partition(std::vector<int> &array, int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            std::swap(array[i], array[j]);
        }
    }

    // swap pivot with the greater element at i
    std::swap(array[i + 1], array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
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
    quickSort(a, 0, a.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Bubble Sort Time: " << elapsed.count() << " nanoseconds" << std::endl;

    print(a);

    return 0;
}