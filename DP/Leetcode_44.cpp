#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for(int i = 0; i < p.size(); i++)
    {
        // 判断边界条件非空匹配式，匹配空字符，只有全为‘*’才可以
        if(p[i]=='*')
            dp[0][i+1] = true;
        else{
            break;
        }
    }
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < p.size(); j++)
        {
            if((isalpha(p[j])&&p[j]==s[i])&&p[j]=='?')
                dp[i + 1][j + 1] = dp[i][j];
            if(p[j]=='*')
                dp[i + 1][j + 1] = dp[i][j + 1] | dp[i + 1][j];
        }
    }
    return dp[s.size()][p.size()];
}