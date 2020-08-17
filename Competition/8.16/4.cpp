#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int minDays(int n)
{
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+1;
        if (i%2==0)
            dp[i] = min(dp[i], dp[i-i/2]+1);
        if (i%3==0)
            dp[i] = min(dp[i], dp[i-2*(i/3)]+1);
    }
    return dp[n];
}

int main()
{
    for(int i = 6; i < 100; i++)
    {
        int res = minDays(i);
        cout << i << " " << res << endl;
    }
    return 0;
}