#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

void cur(vector<int> nums, vector<vector<int>> &res, vector<int> temp, int curr)
{
    cout << curr << endl;
    int n = nums.size();
    if (curr == n)
    {
        res.push_back(temp);
        return;
    }
    cur(nums, res, temp, curr + 1);
    temp.push_back(nums[curr]);
    cur(nums, res, temp, curr + 1);
    return;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    cur(nums, res, temp, 0);
    return res;
}

vector<vector<int>> subsets2(vector<int> &nums)
{
    // 字典序求解
    vector<vector<int>> res;
    unsigned int times = pow(2, nums.size());
    for(unsigned int i = 0; i < times; i++)
    {
        unsigned int j = i;
        int cnt = 0;
        vector<int> temp;
        while(j>0)
        {
            if(j&1U)
                temp.push_back(nums[cnt++]);
            j >>= 1;
        }
        res.push_back(temp);
    }
    return res;
}