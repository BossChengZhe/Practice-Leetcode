#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        unsigned long long aa = abs(a), bb = abs(b);
        unsigned long long res = 0;
        while(aa >= bb) {
            unsigned long long temp = bb, time = 0;
            while(aa >= temp) {
                temp <<= 1;
                time++;
            }
            aa -= (temp >> 1);
            res += (1ull << (time-1));
        }
        
        // 边界判断
        if((((a > 0 && b > 0) || (a < 0 && b < 0)) && res > (1ull << 31)-1) ||
            (((a < 0 && b > 0) || (a > 0 && b < 0)) && res > (1ull << 31)) )
            return INT_MAX;
        return (a > 0 && b > 0) || (a < 0 && b < 0) ? res : -res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x, y;
    while(cin >> x >> y)
        cout << s.divide(x, y) << endl;
    return 0;
}
