#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < 32; j++)
            {
                if((1<<j)&nums[i])
                    bits[j]++;
            }
        }
        int res = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if(bits[i] % 3)
                res += (1 << i);
        }
        return res;
    }
};