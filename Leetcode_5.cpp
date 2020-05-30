#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int max_size = 1, label = 0;
    string res = s.substr(label, max_size);
    for (int i = 0; i < s.size(); i++)
        // 单个字符肯定是回文序列
        dp[i][i] = 1;
    // dp[i][j] = (s[i]==s[j]) and (i-j < 3 or dp[i+1][j-1]==true)
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j] && (i - j < 3 || dp[j + 1][i - 1]))
            {
                dp[j][i] = 1;
                if (i - j + 1 > max_size)
                {
                    max_size = i - j + 1;
                    label = j;
                    res = s.substr(j, max_size);
                }
            }
        }
    }
    return res;
}
int main()
{
    string s = "aaaa";
    string res = longestPalindrome(s);
    cout << res << endl;
    return 0;
}