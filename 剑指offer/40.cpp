#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> res(k, 0);
        for(int i = 0; i < k; i++)
        {
            res[i] = arr[i];
        }
        return res;
    }
};