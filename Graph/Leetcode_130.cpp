#include "iostream"
#include "vector"
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j]!='O')
        return;
    board[i][j] = 'A';
    dfs(board, i - 1, j); // 上
    dfs(board, i + 1, j); // 下
    dfs(board, i, j - 1); // 左
    dfs(board, i, j + 1); // 右
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    if (n == 0)
        return;
    int m = board[0].size();
    for(int i = 0; i < n; i++)
    {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }
    for(int i = 0; i < m; i++)
    {
        dfs(board, 0, i);
        dfs(board, n - 1, i);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j]=='A')
                board[i][j] = 'O';
            else if(board[i][j]=='O')
                board[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> board = {{'O', 'O'}, {'O', 'O'}};
    solve(board);
    return 0;
}