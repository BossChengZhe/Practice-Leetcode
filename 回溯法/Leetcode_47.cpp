#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void cur(vector<vector<int>> &res, vector<int> nums, vector<int> &temp_res)
{
    if(temp_res.size()==nums.size())
    {
        res.push_back(temp_res);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==INT_MIN||(i&&nums[i]==nums[i-1]))
            continue;
        int temp = nums[i];
        nums[i] = INT_MIN;
        temp_res.push_back(temp);
        cur(res, nums, temp_res);
        temp_res.pop_back();
        nums[i] = temp;
    }
    return;
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    // 还是回溯法，不过要加入重复判断
    vector<vector<int>> res;
    vector<int> temp_res;
    cur(res, nums, temp_res);
    return res;
}