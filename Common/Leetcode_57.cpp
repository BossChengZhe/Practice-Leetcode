#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int n = intervals.size();
    int left = 0, right = n - 1;
    while(left<right)
    {
        int mid = left + ((right - left) >> 1);
        if(newInterval[0] <= intervals[mid][0])
            right = mid;
        else
            left = mid + 1;
    }
    if(left==n-1&&newInterval[0]>intervals[left][0])
        left++;
    intervals.insert(intervals.begin() + left, newInterval);
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

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    insert(intervals, newInterval);
    return 0;
}