#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0, end = 0, maxpos = 0, n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            if(maxpos >= i)
            {
                maxpos = max(maxpos, i + nums[i]);
                if(i==end)
                {
                    res++;
                    end = maxpos;
                }
            }
        }
        return res;
    }
};