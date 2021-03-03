#include "vector"
#include "iostream"
using namespace std;

class NumArray
{
public:
    vector<int> temp;
    NumArray(vector<int> &nums)
    {
        temp.resize(nums.size() + 1, 0);
        for(int i = 1; i < temp.size(); i++)
        {
            update(temp, nums[i - 1], i);
        }
        nums = temp;
    }

    int sumRange(int i, int j)
    {
        getsum(j+1, temp) -getsum(i, temp);
    }

    int low(int i)
    {
        return i & -i;
    }
    void update(vector<int>&c, int k, int i)
    {
        while(i < c.size())
        {
            c[i] += k;
            i += low(i);
        }
    }
    int getsum(int i, vector<int> &c)
    {
        int res = 0;
        while(i > 0)
        {
            res += c[i];
            i -= low(i);
        }
        return res;
    }
};
