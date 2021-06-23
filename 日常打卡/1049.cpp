#include <bits/stdc++.h>
using namespace std;

// 01背包问题
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto &i : stones) {
            sum += i;
        }
        int neg = sum / 2;

        // 背包大小为sum/2,一共有stones.size()个物品
        // vector<vector<int>> dp(stones.size() + 1, vector<int>(neg + 1, 0));
        // for(size_t i = 1; i < dp.size(); i++) {
        //     int x = stones[i - 1];
        //     for(size_t j = 0; j <= neg; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         if(j >= x)
        //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - x] + x);
        //     }
        // }
        // return abs(sum - 2 * dp[stones.size()][neg]);

        vector<int> dp(neg + 1, 0);
        for(size_t i = 1; i < dp.size(); i++) {
            int x = stones[i - 1];
            for(size_t j = neg; j >= 0; j--) {
                if(j >= x)
                    dp[j] = max(dp[j], dp[j - x] + x);
            }
        }
        return abs(sum - 2 * dp[neg]);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
