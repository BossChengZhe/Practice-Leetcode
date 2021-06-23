#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid))
                high = mid ;
            else
                low = mid + 1;
        }
        return low;
    }
};