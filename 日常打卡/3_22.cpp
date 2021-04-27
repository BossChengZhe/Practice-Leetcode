#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        uint32_t flag = 1;
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (flag << 1))
                cnt++;
        }
        return cnt;
    }
};