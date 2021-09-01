#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = INT_MIN;
        for (auto &i : dp)
        {
            res = max(res, i);
        }
        return res;
    }
};

