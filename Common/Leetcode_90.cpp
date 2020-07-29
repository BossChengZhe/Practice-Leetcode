#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

void curr(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int current)
{
    res.push_back(temp);
    int n = nums.size();
    if (current == n)
        return;
    for (int i = current; i < n; i++)
    {
        if (i > current && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        curr(nums, res, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    curr(nums, res, temp, 0);
    return res;
}