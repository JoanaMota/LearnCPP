#include <iostream>
#include <vector>

long merge(std::vector<int> &arr, int left, int middle, int right, long &inversions)
{
    // Crate the Left and Right sorted vectors
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;
    std::vector<int> vecLeft(sizeLeft);
    std::vector<int> vecRight(sizeRight);

    int itLeft{0}, itRight{0};
    for (; itLeft < sizeLeft; itLeft++)
    {
        vecLeft[itLeft] = arr[left + itLeft];
    }
    for (; itRight < sizeRight; itRight++)
    {
        vecRight[itRight] = arr[middle + itRight + 1];
    }
    itLeft = 0;
    itRight = 0;
    int itMerged{left};
    while (itLeft < sizeLeft && itRight < sizeRight)
    {
        if (vecLeft[itLeft] <= vecRight[itRight])
        {
            arr[itMerged] = vecLeft[itLeft];
            itLeft++;
        }
        else
        {
            inversions += sizeLeft - itLeft;
            arr[itMerged] = vecRight[itRight];
            itRight++;
        }
        itMerged++;
    }

    while (itLeft < sizeLeft)
    {
        arr[itMerged] = vecLeft[itLeft];
        itLeft++;
        itMerged++;
    }
    while (itRight < sizeRight)
    {
        arr[itMerged] = vecRight[itRight];
        itRight++;
        itMerged++;
    }
    return inversions;
}
long mergeSort(std::vector<int> &arr, int left, int right, long &inversions)
{
    if (left >= right)
    {
        return inversions;
    }
    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle, inversions);
    mergeSort(arr, middle + 1, right, inversions);

    merge(arr, left, middle, right, inversions);
    return inversions;
}

long countInversions(std::vector<int> &arr)
{
    long inversions{0};
    mergeSort(arr, 0, arr.size() - 1, inversions);
    return inversions;
}
void print(std::vector<int> arr)
{
    for (int val : arr)
        std::cout << val << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {2, 1, 3, 1, 2};
    std::cout << countInversions(arr) << std::endl;
    print(arr);
    return 0;
}