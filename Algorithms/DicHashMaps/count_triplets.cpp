#include <iostream>
#include <vector>
#include <unordered_map>

long countTriplets(std::vector<long> &arr, long r)
{
    std::unordered_map<long, long> arrGeometryProgression(arr.size());
    std::unordered_map<long, long> repeatedNumbers(arr.size());
    long tripletCounter{0};
    for (int i = 0; i < arr.size(); i++)
    {
        if (repeatedNumbers.count(arr[i]))
        {
            tripletCounter += repeatedNumbers[arr[i]];
        }
        if (arrGeometryProgression.count(arr[i]))
        {
            repeatedNumbers[arr[i] * r] += arrGeometryProgression[arr[i]];
        }

        arrGeometryProgression[arr[i] * r]++;
    }
    return tripletCounter;
}

int main()
{
    std::vector<long> arr = {1, 3, 9, 9, 27, 81};
    long out = countTriplets(arr, 3);
    std::cout << out << std::endl;
    return 0;
}