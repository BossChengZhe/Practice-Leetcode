#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), 1);
        int res = 0;
        for(int i = 1; i < dp.size(); i++)
        {
            int tempmax = 0;
            for(int j = 0; j < i; j++)
            {
                if(envelopes[j][1] < envelopes[i][1])
                    tempmax = max(tempmax, dp[j] + 1);
            }
            dp[i] = max(dp[i], tempmax);
            res = max(res, tempmax);
        }
        return res;
    }
};