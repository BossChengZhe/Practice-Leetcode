#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int pre=nums[0], res=0;
    for(int i = 1; i < nums.size(); i++)
    {
        pre = max(nums[i] + pre, nums[i]);
        res = max(pre, res);
    }
    return res;
}