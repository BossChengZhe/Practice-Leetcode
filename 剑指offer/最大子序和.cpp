#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            pre = max(nums[i], pre+nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};