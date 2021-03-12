#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<bool>> dp;
    int res;

public:
    int movingCount(int m, int n, int k)
    {
        dp = vector<vector<bool>>(m, vector<bool>(n, false));
        dp[0][0] = true;
        res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(dp[i][j])
                    update(i, j, k);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(dp[i][j])
                    res++;
        return res;
    }
    int getsum(int n)
    {
        int res = 0;
        while (n)
        {
            res += (n % 10);
            n /= 10;
        }
        return res;
    }
    void update(int i, int j, int k)
    {
        if (i - 1 >= 0 && getsum(i - 1) + getsum(j) <= k && !dp[i-1][j])
            dp[i - 1][j] = true;
        if (i + 1 < dp.size() && getsum(i + 1) + getsum(j) <= k && !dp[i+1][j])
            dp[i + 1][j] = true;
        if (j + 1 < dp[0].size() && getsum(j + 1) + getsum(i) <= k && !dp[i][j+1])
            dp[i][j + 1] = true;
        if (j - 1 >= 0 && getsum(j - 1) + getsum(i) <= k && !dp[i][j-1])
            dp[i][j - 1] = true;
    }
};