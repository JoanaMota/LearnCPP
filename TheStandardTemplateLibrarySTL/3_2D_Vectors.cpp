#include <iostream>
#include <vector>

int main()
{
    // Grid with 3 rows and 4 columns
    std::vector<std::vector<int>> grid(3, std::vector<int>(4, 7));

    grid[1].push_back(8);

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            // std::cout << "Row: " << row << " Col: " << col << " " << grid[row][col] << std::endl;
            std::cout << grid[row][col];
        }
        std::cout << std::endl;
    }

    return 0;
}