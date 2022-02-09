#include <iostream>
#include <vector>
#include <array>
#include <chrono> // std::chrono::system_clock

void fill(std::vector<std::vector<int>> &matrix)
{
    int rowSize{(int)matrix.size()};
    int colSize{(int)matrix[0].size()};
    int incr{0};
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            matrix[i][j] = incr;
            incr++;
        }
    }
}
void fill(std::array<std::array<int, 400>, 1100> &matrix)
{
    // int rowSize{(int)matrix.size()};
    // int colSize{(int)matrix[0].size()};
    int incr{0};
    for (int i = 0; i < 1100; i++)
    {
        for (int j = 0; j < 400; j++)
        {
            matrix[i][j] = incr;
            incr++;
        }
    }
}
void fill(int arr[][400], int rowSize, int colSize)
{
    int incr{0};
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            arr[i][j] = incr;
            incr++;
        }
    }
}
void print(std::vector<std::vector<int>> &matrix)
{
    int rowSize{(int)matrix.size()};
    int colSize{(int)matrix[0].size()};
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    // Vector
    std::vector<std::vector<int>> matrix(1100, std::vector<int>(400));
    fill(matrix);

    auto begin = std::chrono::high_resolution_clock::now();

    int val = matrix[58][351];

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Vector    access: " << val << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    // Array
    int arr[1100][400];
    fill(arr, 1100, 400);

    auto begin2 = std::chrono::high_resolution_clock::now();

    int val2 = arr[58][351];

    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    std::cout << "Array     access: " << val2 << " Time: " << elapsed2.count() << " nanoseconds" << std::endl;

    // STL Array
    std::array<std::array<int, 400>, 1100> matrixArr;
    fill(matrixArr);

    auto begin3 = std::chrono::high_resolution_clock::now();

    int val3 = matrixArr[58][351];

    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    std::cout << "STL Array access: " << val3 << " Time: " << elapsed3.count() << " nanoseconds" << std::endl;
}