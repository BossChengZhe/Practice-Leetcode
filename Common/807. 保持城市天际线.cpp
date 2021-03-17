#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> row(grid.size(), 0), col(grid[0].size(), 0);
        int sum = 0;
        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < col.size(); j++)
            {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(grid[i][j], col[j]);
                sum += grid[i][j];
            }
        }
        int current = 0;
        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < col.size(); j++)
            {
                current += min(row[i], col[j]);
            }
        }
        return current - sum;
    }
};