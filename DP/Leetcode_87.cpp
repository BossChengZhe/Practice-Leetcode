#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool isScramble(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    if (len1 != len2)
        return false;
    vector<int> flag(26, 0);
    for (int i = 0; i < len1; i++)
    {
        flag[s1[i] - 'a']++;
        flag[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (flag[i])
            return false;
    vector<vector<vector<bool>>> dp(len1 + 1, vector<vector<bool>>(len1, vector<bool>(len1, false)));
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len1; j++)
            dp[1][i][j] = s1[i] == s2[j];
    for (int i = 2; i <= len1; i++)
    {
        // 遍历所有长度
        for (int j = 0; j < len1 - i + 1; j++)
        {
            // 遍历s1的起点
            for (int k = 0; k < len1 - i + 1; k++)
            {
                // 遍历s2的起点
                for (int l = 1; l < i; l++)
                {
                    // 在长度为i的子串中遍历分割点
                    dp[i][j][k] = (dp[l][j][k] && dp[i - l][j + l][k + l]) || (dp[l][j][k + i - l] && dp[i - l][j + l][k]);
                    if (dp[i][j][k])
                        // 说明该分割点能使两个子串互为扰乱
                        break;
                }
            }
        }
    }
    return dp[len1][0][0];
}

bool isScramble2(string s1, string s2)
{
    if(s1==s2)
        return true;
    int len1 = s1.size(), len2 = s2.size();
    if (len1 != len2)
        return false;
    vector<int> flag(26, 0);
    for (int i = 0; i < len1; i++)
    {
        flag[s1[i] - 'a']++;
        flag[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (flag[i])
            return false;

    for (int len = 1; len < len1; len++)
        if ((isScramble2(s1.substr(0, len), s2.substr(0, len)) && isScramble2(s1.substr(len), s2.substr(len))) ||
            (isScramble2(s1.substr(0, len), s2.substr(len1 - len)) && isScramble2(s1.substr(len), s2.substr(0, len1 - len))))
            return true;
    return false;
}