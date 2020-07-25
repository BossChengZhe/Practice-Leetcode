#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

bool check(vector<int> &nums, long long sums, int m)
{
    int cnt = 1;
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > sums)
        {
            cnt++;
            sum = nums[i];
        }
    }
    if (sum > sums)
        cnt++;
    return cnt > m;
}

int splitArray(vector<int> &nums, int m)
{
    long long low = 0, high = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        low = (low > nums[i]) ? low : nums[i];
        high += nums[i];
    }
    while (low < high)
    {
        long long mid = (high - low) / 2 + low;
        if (!check(nums, mid, m))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int splitArray2(vector<int> &nums, int m)
{
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + nums[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(m, i); j++)
        {
            for(int k = 0; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
            }
        }
    }
    return dp[n][m];
}