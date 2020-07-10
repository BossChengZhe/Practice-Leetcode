#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

/***************************************
 * 首先当前只有三个状态，分别是可交易，冷冻，以及可买入三种状态
 * 今天的利润和昨天的状态有很大关系，所以可以采用dp的方式解题
 * 当前状态为冷冻时，今天的利润就等于昨天的利润
 * 当前状态为可买入时，昨天要么是冷冻期，要么是可买入，在昨天的这两个状态中选一个状态较大的就好
 * 当前状态为可抛售时，那么昨天的状态可能为可买入或者还是处于可抛售的状态
 **************************************/
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    int n = prices.size();
    vector<int> dp(3, 0); // 0买入，1卖出，2冷冻
    dp[0] = -prices[0];
    int cool_down = 0, sell = 0, buy = 0;
    for (int i = 1; i < n; i++)
    {
        cool_down = dp[1];
        sell = max(dp[0] + prices[i], dp[1]);
        buy = max(dp[0], dp[2] - prices[i]);
        dp[0] = buy;
        dp[1] = sell;
        dp[2] = cool_down;
    }
    return max(dp[1], dp[2]);
}