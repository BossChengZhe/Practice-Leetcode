#include "iostream"
#include "map"
#include "vector"
using namespace std;

bool isValidSudoku(vector<vector<char>> &board,vector<map<char, int>> &row, vector<map<char, int>> &column, vector<map<char, int>> &block)
{
    // 初始化用来记录行、列、九宫格的map
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

bool cur(int i, int j, int cnt, vector<vector<char>> &board, vector<map<char, int>> &row, vector<map<char, int>> &column, vector<map<char, int>> &block)
{
    if(j==9){
        j=0;
        i++;
    }
    if (cnt >= 81)
        return true;
    while (i < 9 && j < 9 && board[i][j] != '.')
    {
        j++;
        cnt++;
        if (j == 9)
        {
            i++;
            j = 0;
        }
    }
    if (cnt >= 81)
        return true;

    int b = (i / 3) * 3 + j / 3;

    for (int k = 1; k <= 9; k++)
    {
        if (row[i]['0' + k] == 1 || column[j]['0' + k] == 1 || block[b]['0' + k] == 1)
            // 当前数字已经存在于行、列、九宫格中时，继续循环
            continue;
        row[i]['0' + k] = 1;
        column[j]['0' + k] = 1;
        block[b]['0' + k] = 1;
        board[i][j] = '0' + k;
        cnt++;
        if (cur(i, j + 1, cnt, board, row, column, block))
            return true;

        cnt--;
        board[i][j] = '.';
        row[i]['0' + k] = 0;
        column[j]['0' + k] = 0;
        block[b]['0' + k] = 0;  
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    vector<map<char, int>> column(9, map<char, int>()), row(9, map<char, int>()), block(9, map<char, int>());
    if (!isValidSudoku(board, row, column, block))
        return;
    cur(0, 0, 0, board, row, column, block);
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    return 0;
}