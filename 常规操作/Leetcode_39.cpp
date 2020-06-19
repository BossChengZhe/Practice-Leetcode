#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

void cur(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp_res, int start)
{
    if(target==0)
    {
        res.push_back(temp_res);
        return;
    }
    for(int i = start; i < candidates.size()&&target>=candidates[i]; i++)
    {
        temp_res.push_back(candidates[i]);
        cur(candidates, target - candidates[i], res, temp_res, i);
        temp_res.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp_res;
    cur(candidates, target, res, temp_res, 0);
    return res;
}

int main()
{
    vector<int> candidate = {2, 3, 6, 7};
    combinationSum(candidate, 7);
    return 0;
}