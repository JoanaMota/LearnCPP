#include <iostream>
#include <vector>
#include <queue>

int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid)
{
    if (grid[0][0] == 1)
    {
        return -1;
    }
    int length{0};
    int rowMax{(int)grid.size()};
    int colMax{(int)grid.size()};

    std::vector<std::vector<bool>> visited(rowMax, std::vector<bool>(colMax, false));
    std::vector<int> directions =
        {-1, -1,
         -1, 0,
         -1, 1,
         0, -1,
         0, 1,
         1, -1,
         1, 0,
         1, 1};
    int nrDirections{8 * 2};

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int k = q.size();
        length++; // increase here since we will check all 8 directions of this coordinates first
        for (int i = 0; i < k; i++)
        {
            auto temp = q.front();
            q.pop();
            if (temp.first == (rowMax - 1) && temp.second == (colMax - 1))
            {
                return length;
            }

            for (int i = 0; i < nrDirections; i += 2)
            {
                int row = temp.first + directions[i];
                int col = temp.second + directions[i + 1];
                if (row < rowMax && col < colMax && row >= 0 && col >= 0 && grid[row][col] != 1 && visited[row][col] == false)
                {
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }
    }
    return -1;
}
int main()
{
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    std::cout << shortestPathBinaryMatrix(grid) << std::endl;
    return 0;
}