#include "iostream"
#include "map"
#include "vector"
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    // 初始化用来记录行、列、九宫格的map
    vector<map<char, int>> column(9, map<char, int>()), row(9, map<char, int>()), block(9, map<char, int>());
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != '.')
            {
                row[i][board[i][j]]++;
                column[j][board[i][j]]++;
                block[(i / 3) * 3 + j / 3][board[i][j]]++;
                if (row[i][board[i][j]] > 1 || column[j][board[i][j]] > 1 || block[(i / 3) * 3 + j / 3][board[i][j]] > 1)
                    return false;
            }
        }
    }
    return true;
}