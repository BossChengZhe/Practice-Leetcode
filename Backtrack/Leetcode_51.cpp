#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

bool is_vaild(vector<string> &board, int row, int column)
{
    int n = board.size();
    for (int i = 0; i < row; i++)
        if (board[i][column] == 'Q')
            return false;
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void backtrack(vector<vector<string>> &res, vector<string> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_vaild(board, row, i))
        {
            board[row][i] = 'Q';
            backtrack(res, board, row + 1);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(res, board, 0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[0][j] << endl;
        }
        cout << endl;
    }
    return res;
}

int main()
{
    solveNQueens(4);
    return 0;
}