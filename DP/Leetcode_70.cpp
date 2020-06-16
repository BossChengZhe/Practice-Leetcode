#include <iostream>
#include <string>
#include <vector>
using namespace std;

int climbStairs_dp(int n)
{
    // 动态规划 dp[i]=dp[i-1]+dp[i-2] (i>2)
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n+1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

void cur(int n, int &res, int cnt){
    if(cnt>n)
        return;
    else if(cnt==n){
        res++;
        return;
    }
    else{
        cur(n, res, cnt + 1);
        cur(n, res, cnt + 2);
    }
}

int climbStairs(int n)
{
    int res = 0;
    cur(n, res, 0);
    return res;
}