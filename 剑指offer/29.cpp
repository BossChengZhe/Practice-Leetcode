#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (!matrix.size())
            return {};
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        while (left <= right && up <= down)
        {
            // printf("%d %d %d %d\n", left, right, up, down);
            for (int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            for (int j = up + 1; j <= down; j++)
                res.push_back(matrix[j][right]);
            for (int i = right - 1; i >= left && up!=down; i--)
                res.push_back(matrix[down][i]);
            for (int j = down - 1; j > up && left != right; j--)
                res.push_back(matrix[j][left]);
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};