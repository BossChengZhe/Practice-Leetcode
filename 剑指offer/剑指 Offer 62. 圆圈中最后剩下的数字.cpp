#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (size_t i = 2; i < n+1; i++)
        {
            pos = (pos + m) % i;
        }
        return pos;
    }
};