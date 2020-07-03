#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        int right = intervals[i][1], left = intervals[i][0];
        for (int j = i + 1; j < intervals.size(); j++, i++)
        {
            if (intervals[j][0] <= right)
                right = max(right, intervals[j][1]);
            else
            {
                i = j - 1;
                break;
            }
        }
        res.push_back({left, right});
    }
    return res;
}