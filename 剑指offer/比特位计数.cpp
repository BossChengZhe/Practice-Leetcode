#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        int high = 0;
        for (size_t i = 1; i < n+1; i++)
        {
            if(i &(i-1) == 0)
                high = i;
            bits[i] = bits[i - high];
        }
        return bits;
    }
};