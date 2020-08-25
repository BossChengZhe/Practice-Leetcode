#include "iostream"
#include "vector"
using namespace std;

void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> temp, int node, int last)
{
    if (node == nums.size())
    {
        if(temp.size() >=2)
            res.push_back(temp);
        return;
    }
    if(nums[node]>=last)
    {
        temp.push_back(nums[node]);
        dfs(nums, res, temp, node + 1, nums[node]);
        temp.pop_back();
    }
    if(nums[node]!=last)
        dfs(nums, res, temp, node + 1, last);
}

vector<vector<int>> findSubsequences2(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    dfs(nums, res, temp, 0, INT_MIN);
    return res;
}