#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        int n = nums.size();
        stack<int> s;
        for(int i = 0; i < n*2; i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i%n])
            {
                res[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};

// 单调栈