#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

int get_Range(vector<vector<int>> &range, int z)
{
    int low = 0, high = range.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (range[mid][0] >= z)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

void get_max(vector<vector<int>> &range, int start, int cnt, int &res)
{
    for (int i = start; i < range.size(); i++)
    {
        int low = get_Range(range, range[i][1] + 1);
        if (range[i][1] > range[low][0] && low == range.size() - 1)
        {
            res = max(res, cnt);
            return;
        }
        get_max(range, low, cnt + 1, res);
    }
}

int maxNonOverlapping(vector<int> &nums, int target)
{
    int res = 0;
    vector<vector<int>> range;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == target)
            {
                range.push_back({i, j});
                break;
            }
        }
    }
    get_max(range, 0, 0, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    maxNonOverlapping(nums, 2);
    return 0;
}