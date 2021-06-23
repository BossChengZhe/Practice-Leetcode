#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    * dp[i][j][k]表示前i个工作中选择j个员工，利润最起码是k
    * 二维背包问题的转移公式：
    * 如果不能够成功执行：dp[i][j][k] = dp[i-1][j][k]
    * 如果不能够成功执行 ：dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-group[i]][max(0, k-profit[i]]
    */
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit+1, 0));
        for(size_t i = 0; i < n+1; i++) {
            dp[i][0] = 1;
        }
        int worknum = group.size(), MOD = (int)1e9 + 7;
        for(size_t i = 0; i < worknum; i++) {
            int worker = group[i], pf = profit[i];
            for(int j = n; j >= worker; j--) {
                for(int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - worker][max(0, k - pf)])%MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};