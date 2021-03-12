#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        for (int i = 2; i < target; i++)
        {
            vector<int> temp(i, 0);
            if (i % 2 == 0)
            {
                int tem = target - i / 2;
                int first = tem / i - (i - 1) / 2;
                if(first <= 0)
                    break;
                if (tem % i == 0 && first > 0)
                {
                    for (int j = 0; j < i; j++)
                        temp[i] = first++;
                }
            }
            else
            {
                int first = target / i - (i - 1) / 2;
                if(first <= 0)
                    break;
                if (target % i == 0 && first > 0)
                {
                    for (int j = 0; j < i; j++)
                        temp[i] = first++;
                }
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};