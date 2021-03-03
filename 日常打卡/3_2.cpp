#include "vector"
#include "iostream"
using namespace std;
class NumMatrix
{
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>> &matrix)
    {
        mat.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        mat[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++)
            mat[i][0] = matrix[i][0] + mat[i - 1][0];
        for (int i = 1; i < matrix[0].size(); i++)
            mat[0][i] = matrix[0][i] + mat[0][i - 1];
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int getvalue(int row, int col)
    {
        if(row <0 || col < 0)
            return 0;
        return mat[row][col];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return getvalue(row2, col2) - getvalue(row1 - 1, col2) - getvalue(row2, col1 - 1) + getvalue(row1 - 1, col1 - 1);
    }
};