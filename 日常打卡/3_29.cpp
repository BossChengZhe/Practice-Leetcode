#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        int i = 32;
        while (i > 0)
        {
            res = res << 1;
            res += (n%2);
            n >>=1;
            i--;
        }
        return res;
    }
};