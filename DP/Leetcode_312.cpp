#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    vector<int> nums2(n + 2, 0);
    nums2[0] = 1, nums2[n + 1] = 1;
    for (int i = 0; i < n; i++)
        nums2[i + 1] = nums[i];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j <= n + 1; j++)
        {
            for (int k = i + 1; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums2[i] * nums2[k] * nums2[j]);
        }
    }
    return dp[0][n + 1];
}