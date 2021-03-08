#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string z;
    vector<vector<string>> res;
    vector<vector<bool>> dp;

public:
    int minCut(string s)
    {
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), true));
        int len = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }
        }
        vector<int> f(len, INT_MAX);
        for (int i = 0; i < len; i++)
        {
            if(dp[0][i])
            {
                f[i] = 1;
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if(dp[j][i])
                    f[i] = min(f[i], f[j] + 1);
            }
        }
        return f[len - 1];
    }
};