#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int tempmax = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    tempmax = max(tempmax, dp[j] + 1);
            }
            dp[i] = max(dp[i], tempmax);
            res = max(res, tempmax);
        }
        return res;
    }
};