#include "iostream"
#include "vector"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int res = 0;
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if(obstacleGrid[0][0] == 1)
        return 0;
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!i&&!j)
                continue;
            if(obstacleGrid[i][j]==1)
            {
                dp[i][j] = (i >= 1) ? dp[i - 1][j] : 0;
                dp[i][j] += (j >= 1) ? dp[i][j - 1] : 0;
            }
        }
    }
    return dp[n - 1][m - 1];
}