#include "iostream"
#include "string"
#include "vector"
using namespace std;

int longestValidParentheses(string s)
{
    // 动态规划解决最长有效括号的问题
    vector<int> dp(s.size());
    int res=0;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i]==')'&&s[i-1]=='(')
            dp[i] = (i - 2 >= 0) ? 2 + dp[i - 2] : 2;
        if(s[i]==')'&&s[i-1]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
            dp[i] = (i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] + 2 + dp[i - 1] : 2 + dp[i - 1];
        res = (res >= dp[i]) ? res : dp[i];
    }
    return res;
}

int main()
{
    longestValidParentheses("())((())");
    return 0;
}