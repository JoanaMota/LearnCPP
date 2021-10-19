#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <assert.h>

int getQuadrant(int row, int column)
{
    return (row / 3) * 3 + column / 3;
}

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::vector<std::unordered_set<char>> squareVM(board.size(), std::unordered_set<char>());
    std::vector<std::unordered_set<char>> columnVM(board.size(), std::unordered_set<char>());

    for (int row = 0; row < board.size(); row++)
    {
        std::unordered_set<char> rowM;
        for (int column = 0; column < board[0].size(); column++)
        {
            if ('.' == board[row][column])
            {
                continue;
            }
            char value = board[row][column];
            std::cout << "value: " << value << std::endl;

            if (rowM.find(value) == rowM.end())
            {
                rowM.insert(value);
            }
            else
            {
                std::cout << "Invalid row " << std::endl;
                return false;
            }

            if (!columnVM[column].count(value))
            {
                std::cout << "Valid column " << column << std::endl;
                columnVM[column].insert(value);
            }
            else
            {
                std::cout << "Invalid column " << column << std::endl;
                return false;
            }
            int box = getQuadrant(row, column);
            std::cout << box << std::endl;
            if (squareVM[box].find(value) == squareVM[box].end())
            {
                squareVM[box].insert(value);
            }
            else
            {
                std::cout << "Invalid rec " << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{

    std::vector<std::vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},

         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},

         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::cout << std::boolalpha << isValidSudoku(board) << std::endl;
}