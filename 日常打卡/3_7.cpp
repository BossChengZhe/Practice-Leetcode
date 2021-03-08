#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<string>> res;
    vector<vector<bool>> dp;
    string z;

public:
    vector<vector<string>> partition(string s)
    {
        int len = s.length();
        z = s;
        dp.resize(len, vector<bool>(len, true));
        for (int i = len - 1; i > -1; i--)
        {
            for (int j = i + 1; j < len; j++)
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        dfs({}, 0);
    }

    void dfs(vector<string> temp, int pos)
    {
        int len = z.length();
        if (pos == len)
        {
            res.push_back(temp);
            return;
        }
        
        for (int i = pos; i < len; i++)
        {
            if (dp[pos][i])
            {
                temp.push_back(z.substr(pos, i - pos + 1));
                dfs(temp, i + 1);
            }
            temp.pop_back();
        }
    }
};