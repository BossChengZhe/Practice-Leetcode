#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = nums[i];
        int res = INT32_MAX;
        while (j < nums.size())
        {
            if(sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            else {
                j++;
                if(j == nums.size()) break;
                sum += nums[j];
            }
        }
        return res==INT32_MAX?0:res;
    }
};