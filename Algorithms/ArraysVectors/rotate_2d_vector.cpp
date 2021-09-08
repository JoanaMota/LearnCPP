#include <iostream>
#include <vector>
#include <cmath>
void print(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void rotate(std::vector<std::vector<int>> &matrix)
{
    int mSize = matrix.size();
    for (int rowNr = 0; rowNr < mSize - 1; ++rowNr)
    {
        for (int colmunNr = rowNr; colmunNr < mSize - 1 - rowNr; ++colmunNr)
        {
            std::cout << "colmunNr: " << colmunNr << " rowNr: " << rowNr << std::endl;

            int corner1 = matrix[rowNr][colmunNr];
            int corner2 = matrix[colmunNr][mSize - 1 - rowNr];
            int corner3 = matrix[mSize - 1 - rowNr][mSize - 1 - colmunNr];
            int corner4 = matrix[mSize - 1 - colmunNr][rowNr];

            std::cout << "corner1: " << corner1 << " corner2: " << corner2 << " corner3: " << corner3 << " corner4: " << corner4 << std::endl;

            matrix[mSize - 1 - colmunNr][rowNr] = corner3;             // corner4 = corner3
            matrix[mSize - 1 - rowNr][mSize - 1 - colmunNr] = corner2; // corner3 = corner2
            matrix[colmunNr][mSize - 1 - rowNr] = corner1;             // corner2 = corner1
            matrix[rowNr][colmunNr] = corner4;                         // corner1 = temp
            print(matrix);
        }
    }
}

int main()
{
    std::vector<std::vector<int>> nums1 = {{1, 2}, {3, 4}};
    // std::vector<std::vector<int>> nums1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(nums1);
    rotate(nums1);
    print(nums1);
    return 0;
}