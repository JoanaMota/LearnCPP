#include <iostream>
#include <vector>
#include <set>
void setZeroes(std::vector<std::vector<int>> &matrix)
{
    std::set<int> zRows;
    std::set<int> zColumns;
    for (int row = 0; row < matrix.size(); ++row)
    {
        for (int column = 0; column < matrix[0].size(); ++column)
        {
            if (matrix[row][column] == 0)
            {
                zRows.insert(row);
                zColumns.insert(column);
            }
        }
    }
    for (int row = 0; row < matrix.size(); ++row)
    {
        for (int column = 0; column < matrix[0].size(); ++column)
        {
            if (zRows.count(row) || zColumns.count(column))
            {
                matrix[row][column] = 0;
            }
        }
    }
}

void setZeroesConstSpace(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // first row
    bool isRowZero = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            isRowZero = true;
            break;
        }
    }

    // first column
    bool isColumnZero = false;
    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            isColumnZero = true;
            break;
        }
    }

    // check matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (isRowZero)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    if (isColumnZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
}

void print(std::vector<std::vector<int>> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums[0].size(); ++j)
        {
            std::cout << nums[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    print(matrix);
    return 0;
}