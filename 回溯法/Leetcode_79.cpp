#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool back_track(vector<vector<char>> &board, int column, int row, int index, string &word)
{
    int m = board.size(), n = board[0].size();
    if (board[row][column] == word[index])
    {
        board[row][column] = 0;
        if (index == word.length() - 1)
            return true;
        if((row > 0 && board[row - 1][column] != 0 && back_track(board, column, row - 1, index + 1, word))||
            (column > 0 && board[row][column - 1] != 0 && back_track(board, column - 1, row, index + 1, word))||
            (row < m - 1 && board[row + 1][column] != 0 && back_track(board, column, row + 1, index + 1, word))||
            (column < n - 1 && board[row][column + 1] != 0 && back_track(board, column + 1, row, index + 1, word)))
            return true;
        board[row][column] = word[index];
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (back_track(board, j, i, 0, word))
                return true;
    return false;
}