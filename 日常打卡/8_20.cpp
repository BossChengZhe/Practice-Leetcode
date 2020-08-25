#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(vector<vector<char>> &board, int i, int j)
{
    if (i < 0 || j < 0 || i > board.size() || j > board.size())
        return;

    if (board[i][j] == 'M' || board[i][j]<='8' && board[i][j] >='1' || board[i][j] == 'B')
        //当前是已经标记空白格，或者已经标记过得炸弹相邻区域，或者是炸弹
        return;
    if (board[i][j] == 'A')
        // 与炸弹临近
        
}

vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
{
    if (board[click[0]][click[1]] == 'M')
    {
        board[click[0]][click[1]] = 'X';
        return board;
    }

    // 对临近炸弹的空格进行标识
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'M')
            {
                for (int k = max(0, i - 1); k <= min(i + 1, (int)board.size() - 1); k++)
                    for (int l = max(0, j - 1); l <= min(j + 1, (int)board[0].size() - 1); l++)
                        if (board[k][l] == 'E')
                            board[k][l] = 'A';
            }
        }
    }
}