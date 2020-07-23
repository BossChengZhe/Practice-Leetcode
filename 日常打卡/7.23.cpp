#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i||j)
                dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
    return dp[m][n];
}