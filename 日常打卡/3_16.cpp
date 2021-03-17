#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, left = 0, right = res[0].size() - 1, down = res.size() - 1;
        
        int times = min(right + 1, down + 1) / 2 + min(right + 1, down + 1) % 2;
        int cnt = 0;
        for (int i = 0; i < times; i++)
        {
            if (left == right)
            {
                for (int j = up; j <= down; j++)
                    res[j][left]=++cnt;
                break;
            }
            if (up == down)
            {
                for (int j = left; j <= right; j++)
                    res[up][j]=++cnt;
                break;
            }
            for (int j = left; j < right; j++)
                res[up][j]=++cnt;
            for (int j = up; j < down; j++)
                res[j][right]=++cnt;
            for (int j = right; j > left; j--)
                res[down][j]=++cnt;
            for (int j = down; j > up; j--)
                res[j][left]=++cnt;
            right--;
            left++;
            up++;
            down--;
        }
        return res;
    }
};