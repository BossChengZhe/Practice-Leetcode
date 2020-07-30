#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        for (int j = 2; j < i; j++)
        {
            int temp = max(i-j, dp[i-j]);
            if (dp[i] >= j * temp)
                break;
            dp[i] = j * temp;
        }
    }
    return dp[n];
}

int main()
{
    int res = integerBreak(58);
    return 0;
}