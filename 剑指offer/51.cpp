#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution
{
public:
    int low(int x)
    {
        return x & -x;
    }
    void update(vector<int> &c, int i)
    {
        while (i < c.size())
        {
            c[i]++;
            i += low(i);
        }
    }
    int query(vector<int> &c, int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += c[i];
            i -= low(i);
        }
        return ans;
    }
    int reversePairs(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (auto &i : nums)
            i = lower_bound(temp.begin(), temp.end(), i) - temp.begin() + 1;
        int res = 0;
        temp.resize(nums.size() + 1, 0);
        fill(temp.begin(), temp.end(), 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res += query(temp, nums[i] - 1);
            update(temp, nums[i]);
        }
        return res;
    }
};