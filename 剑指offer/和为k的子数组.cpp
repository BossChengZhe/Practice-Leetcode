#include <bits/stdc++.h>
using namespace std;


// 前缀和思想

// sums[i] - sums[j] = k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre_sum = 0, res = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        for (auto &x : nums)
        {
            pre_sum += x;
            if(ump.find(pre_sum -k) != ump.end())
                res += ump[pre_sum - k];
            ump[pre_sum]++;
        }
        return res;
    }
};