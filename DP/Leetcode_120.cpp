#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

// int minimumTotal(vector<vector<int>> &triangle)
// {
//     int n = triangle.size();
//     vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//     dp[0][0] = triangle[0][0];
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             if (j == 0)
//                 // 在三角形一行的最左端
//                 dp[i][j] = dp[i - 1][j] + triangle[i][j];
//             else if (j == i)
//                 // 在三角形一行的最右端
//                 dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
//             else
//                 // 在三角形一行的中间
//                 dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
//         }
//     }
//     int res = INT_MAX;
//     for(int i = 0; i < n; i++)
//         res = min(res, dp[n - 1][i]);
//     return res;
// }

int minimumTotal(vector<vector<int>> &triangle)
{
    // 观察状态转移方程可以得到，当前状态只和这一行的前一行相关，所以我们可以采用从右到左的方式更新长度为n的数组，可以达到只使用O(N)的空间
    int n = triangle.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0)
                dp[j] = dp[j] + triangle[i][j];
            else if (j == i)
                dp[j] = dp[j - 1] + triangle[i][j];
            else
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < n; i++)
        res = min(dp[i], res);
    return res;
}