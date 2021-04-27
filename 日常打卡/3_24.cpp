#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int maxnum = nums[0], flag = 0;
        vector<int> left(0, nums.size());
        left[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (maxnum < nums[i])
            {
                maxnum = nums[i];
                flag = i;
            }
            left[i] = min(left[i - 1], nums[i - 1]);
        }
        stack<int> s;
        for(int i = nums.size(); i >= 0; i--)
        {
            int numk = 0;
            while(!s.empty() && s.top() < nums[i])
            {
                numk = s.top();
                s.pop();
                if(numk > left[i])
                    return true;
                s.push(nums[i]);
            }
        }
        return false;
    }
};
