#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums(words.size(), 0);
        for (size_t i = 0; i < words.size(); i++)
        {
            for (auto &j : words[i])
            {
                nums[i] |= (1 << (j - 'a'));
            }
        }
        int res = 0;
        for (size_t i = 0; i < words.size(); i++)
        {
            for (size_t j = i+1; j < words.size(); j++)
            {
                if(!(nums[i] & nums[j]))
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};