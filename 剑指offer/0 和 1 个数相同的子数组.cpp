#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> udm;
        int pre = 0;
        int res = 0;
        udm[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            pre += (nums[i] == 0 ? -1 : 1);
            if(udm.find(pre) == udm.end())
                udm[pre] = i;
            else
                res = max(res, i - udm[pre]);
        }
        return res;
    }
};