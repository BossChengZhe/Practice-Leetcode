#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            int j;
            for (j = i; nums[j] == nums[i] && j < nums.size(); j++)
                cnt++;
            if (cnt == 1)
                res.push_back(nums[i]);
            i += (j - 1);
        }
        return res;
    }
};
// 题目要求为时间复杂度为O(N),空间复杂度为o(1)，两数字异或可以解决这个问题

class Solution1 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++)
            n ^= nums[i];
        int div = 1;
        while(div&n==0)
            div <<= 1;
        int a=0, b=0;
        for(auto i : nums)
        {
            if(i&div)
                a ^= i;
            else
                b ^= i;
        }
        return {a, b};
    }
};