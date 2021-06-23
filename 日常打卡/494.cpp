#include <bits/stdc++.h>
using namespace std;

// 暴力遍历
void depthSearch(vector<int>& nums, int &res, int target, int rank, int flag, int temp) {
    if(rank == nums.size() - 1) {
        if(temp + nums[rank] * flag == target){
            res++;
        }
        return;
    }
    depthSearch(nums, res, target, rank + 1, 1, temp + nums[rank] * flag);
    depthSearch(nums, res, target, rank + 1, -1, temp + nums[rank] * flag);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int res = 0;
    vector<int> flags;
    depthSearch(nums, res, target, 0, 1, 0);
    depthSearch(nums, res, target, 0, -1, 0);
    return res;
}

/*
* x + y = sum(nums)
* x - y = target
* x = (sum(nums)+target) / 2
* y = (sum(nums)-target) / 2
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto &i : nums) {
            sum += i;
        }
        if(target > sum || target%2!=0) {
            return 0;
        }
        int x = (sum + target) / 2;
        int y = (sum - target) / 2;

        /*
        * 有关状态转移公式的说明，dp[i][j]表示从前i个元素中选择和为j的数的方案数
        * 如果当前j < nums[i],那么不能选，dp[i][j] = dp[i-1][j]
        * 如果当前j >= nums[i]，如果不选dp[i][j] = dp[i-1][j]，如果选择dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j]
        */
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(y + 1, 0));
        // dp[0][0] = 1;
        // for(size_t i = 1; i <= nums.size(); i++) {
        //     for(size_t j = 0; j <= y; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         if(j >=  nums[i-1]){
        //             dp[i][j] += dp[i - 1][j - nums[i-1]];
        //         }
        //     }
        // }
        // return dp[nums.size()][y];
        vector<int> dp(y + 1, 0);
        dp[0] = 1;
        for(size_t i = 1; i <= nums.size(); i++) {
            int temp = nums[i - 1];
            for(size_t j = y; j >= 0; j--) {
                if(j > temp) {
                    dp[j] += dp[j - temp];
                }
            }
        }
        return dp.back();
    }
};