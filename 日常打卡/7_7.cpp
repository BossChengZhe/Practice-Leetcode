#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    const int mod = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
        int maxSum = maxVal * 2;
        int pairs = 0;
        unordered_map<int, int> mp;
        int n = deliciousness.size();

        for (auto &i : deliciousness)
        {
            for (size_t sum = 1; sum <= maxSum; sum <<= 1)
            {
                int cnt = mp.count(sum - i) ? mp[sum - i] : 0;
                pairs = (pairs + cnt) % mod;
            }
            mp[i]++;
        }
        return pairs;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> test{1, 1, 1, 3, 3, 3, 7};
    Solution S;
    S.countPairs(test);
    return 0;
}
