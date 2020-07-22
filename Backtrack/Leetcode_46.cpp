#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

void cur(vector<vector<int>> &res, vector<int> nums, vector<int> &temp_res)
{
    if (temp_res.size() == nums.size())
    {
        res.push_back(temp_res);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == INT_MIN)
            continue;
        int temp = nums[i];
        temp_res.push_back(temp);
        nums[i] = INT_MIN;
        cur(res, nums, temp_res);
        temp_res.pop_back();
        nums[i] = temp;
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp_res;
    cur(res, nums, temp_res);
    return res;
}