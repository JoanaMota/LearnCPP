#include <iostream>
#include <vector>

// Print the array
void printArray(std::vector<int> arr)
{
    for (int val : arr)
        std::cout << val << " ";
    std::cout << std::endl;
}

// Merge two subarrays LeftArray and RightArray into arr
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    // Create LeftArray : A[left..mid] and RightArray : A[mid+1..r]
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
        LeftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = arr[mid + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i{0}, j{0}, k;
    k = left;

    // Until we reach either end of either LeftArray or RightArray, pick larger among
    // elements LeftArray and RightArray and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either LeftArray or RightArray,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // m is the point where the array is divided into two subarrays
        int m = left + (right - left) / 2;

        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        printArray(arr);
        // Merge the sorted subarrays
        merge(arr, left, m, right);
    }
}

// Driver program
int main()
{
    std::vector<int> arr = {6, 5, 12, 10, 9, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: \n";
    printArray(arr);
    return 0;
}