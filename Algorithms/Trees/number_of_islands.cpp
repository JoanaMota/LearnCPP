#include <iostream>
#include <vector>

void print(std::vector<std::vector<char>> &grid)
{
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void sinkIsland(std::vector<std::vector<char>> &grid, int row, int col)
{
    if (row < 0 || row >= grid.size())
    {
        return;
    }
    if (col < 0 || col >= grid[0].size())
    {
        return;
    }

    if ('1' == grid[row][col])
    {
        grid[row][col] = '0';
        std::cout << "row: " << row << " col: " << col << std::endl;
        print(grid);
        sinkIsland(grid, row + 1, col);
        sinkIsland(grid, row - 1, col);
        sinkIsland(grid, row, col + 1);
        sinkIsland(grid, row, col - 1);
    }
    return;
}

int numIslands(std::vector<std::vector<char>> &grid)
{
    int countIslands{0};
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if ('1' == grid[row][col])
            {
                sinkIsland(grid, row + 1, col);
                sinkIsland(grid, row - 1, col);
                sinkIsland(grid, row, col + 1);
                sinkIsland(grid, row, col - 1);
                countIslands++;
            }
        }
    }
    return countIslands;
}

int main()
{
    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                           {'1', '1', '0', '1', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '0', '0', '0'}};
    std::vector<std::vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '1', '0', '0'},
                                            {'0', '0', '0', '1', '1'}};

    std::cout << "Number of Islands: " << numIslands(grid2) << std::endl;
    return 0;
}