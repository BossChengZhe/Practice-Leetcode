#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    if (dungeon.size() == 0)
        return 0;
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[n][m - 1] = dp[n - 1][m] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int min_dp = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = min_dp - dungeon[i][j] < 1 ? 1 : min_dp - dungeon[i][j];
        }
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> dun = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    calculateMinimumHP(dun);
    return 0;
}