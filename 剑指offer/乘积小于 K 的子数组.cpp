#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        unsigned long long product = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            while(product >= k){
                product /= nums[left];
                left++;
            }
            res += (i - left + 1);
        }
        return res;
    }
};