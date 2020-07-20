#include "iostream"
#include "vector"
using namespace std;

void cur(int n, int k, int cnt, vector<vector<int>> &res, vector<int> temp, int curr)
{
    if (cnt == k)
        res.push_back(temp);

    for (int i = curr; i <= n; i++)
    {
        temp.push_back(i);
        cur(n, k, cnt + 1, res, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<bool> flag(n, true);
    vector<int> temp;
    cur(n, k, 0, res, temp, 1);
    return res;
}
