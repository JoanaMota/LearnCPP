#include <bits/stdc++.h>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
    int rowStart{0}, columnStart{0};
    int maxSum{-100};
    for (int rowStart = 0; rowStart < 4; rowStart++)
    {
        for (int columnStart = 0; columnStart < 4; columnStart++)
        {
            int sum{0};
            for (int row = rowStart; row < (rowStart + 3); row++)
            {
                for (int column = columnStart; column < (columnStart + 3); column++)
                {
                    if (row == (rowStart + 1) && column == columnStart)
                    {
                        continue;
                    }
                    if (row == (rowStart + 1) && column == (columnStart + 2))
                    {
                        continue;
                    }
                    sum += arr[row][column];
                }
            }
            if (sum > maxSum)
            {
                std::cout << "sum: " << sum << " rowStart: " << rowStart << " columnStart: " << columnStart << std::endl;
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int main()
{

    // vector<vector<int>> arr = {{1, 1, 1, 0, 0, 0},
    //                            {0, 1, 0, 0, 0, 0},
    //                            {1, 1, 1, 0, 0, 0},
    //                            {0, 0, 2, 4, 4, 0},
    //                            {0, 0, 0, 2, 0, 0},
    //                            {0, 0, 1, 2, 4, 0}};
    vector<vector<int>> arr = {{-1, -1, 0, -9, -2, -2},
                               {-2, -1, -6, -8, -2, -5},
                               {-1, -1, -1, -2, -3, -4},
                               {-1, -9, -2, -4, -4, -5},
                               {-7, -3, -3, -2, -9, -9},
                               {-1, -3, -1, -2, -4, -5}};

    int result = hourglassSum(arr);

    std::cout << result << "\n";

    return 0;
}