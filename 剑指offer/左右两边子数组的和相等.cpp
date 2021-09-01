#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];

        int total = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            total += nums[i];
        }

        int pre = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(pre == total -pre-nums[i])
                return i;
            pre += nums[i];
        }
        return -1;
    }
};