#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        if(num < 10)
            return 1;
        string s = to_string(num);
        int p, q, r;
        q = 1;
        int temp = (s[0] - '0') * 10 + (s[1] - '0');
        r = temp > 25 || temp < 10 ? 1 : 2;
        for (int i = 2; i < s.size(); i++)
        {
            p = q;
            q = r;
            r = 0;
            temp = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (temp > 25 || temp < 10)
                r = q;
            else
                r = q + p;
        }
        return r;
    }
};

// dfs是不行的，当num很大是，深度优先便利会消耗很多空间，题目要求是求取数量不是枚举排列。