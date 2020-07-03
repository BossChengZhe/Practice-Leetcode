#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (!matrix.size())
        return {};
    int up = 0, left = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
    vector<int> res;
    int times = min(right + 1, down + 1) / 2 + min(right + 1, down + 1) % 2;
    for (int i = 0; i < times; i++)
    {
        if (left == right)
        {
            for (int j = up; j <= down; j++)
                res.push_back(matrix[j][left]);
            break;
        }
        if (up == down)
        {
            for (int j = left; j <= right; j++)
                res.push_back(matrix[up][j]);
            break;
        }
        for (int j = left; j < right; j++)
            res.push_back(matrix[up][j]);
        for (int j = up; j < down; j++)
            res.push_back(matrix[j][right]);
        for (int j = right; j > left; j--)
            res.push_back(matrix[down][j]);
        for (int j = down; j > up; j--)
            res.push_back(matrix[j][left]);
        right--;
        left++;
        up++;
        down--;
    }
    return res;
}