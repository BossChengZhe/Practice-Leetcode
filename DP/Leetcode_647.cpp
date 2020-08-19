#include "iostream"
#include "vector"
using namespace std;

int countSubstrings(string s)
{
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++)
        dp[i][i] = true;
    int res = len;
    for (int i = len-1; i >= 0; i--)
    {
        for (int j = len-1; j > i; j--)
        {
            if (s[i] == s[j] && (j == i + 1 || dp[i + 1][j - 1]))
            {
                dp[i][j] = true;
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int res = countSubstrings("cabac");
    cout << res << endl;
    return 0;
}