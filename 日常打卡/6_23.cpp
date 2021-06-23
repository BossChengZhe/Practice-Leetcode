#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res;
        while(n) {
            res = n % 2 ? res + 1 : res;
            n /= 2;
        }
        return res;
    }
};