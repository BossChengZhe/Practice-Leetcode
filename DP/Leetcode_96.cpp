#include "iostream"
#include "vector"
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i / 2; j++)
            dp[i] += 2 * dp[j] * dp[i - j - 1];
        dp[i] += i % 2 ? 0 : dp[(i - 1) / 2] * dp[(i - 1) / 2];
    }
    return dp[n];
}