#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) {
                break;
            }
            if(i && nums[i-1]==nums[i])
                continue;
            int k = nums.size() - 1;
            for (int j = i+1; j < nums.size(); j++)
            {
                if(j > i +1&& nums[j ]== nums[j-1])
                    continue;
                while(j < k && nums[i] + nums[j] + nums[k] > 0)
                    k--;
                if(j==k)
                    break;
                if(nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({i, j, k});
            }
        }
        return res;
    }
};