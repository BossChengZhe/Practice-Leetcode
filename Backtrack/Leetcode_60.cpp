#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

string getPermutation(int n, int k)
{
    string res;
    vector<int> nums(n, 0);
    k--;
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    for (int i = 1; i < n; i++)
    {
        int times = 1;
        for (int j = 1; j <= n - i; j++)
            times *= j;
        res += to_string(nums[k / times]);
        nums[k / times] = INT_MAX;
        k %= times;
        sort(nums.begin(), nums.end());
    }
    res += to_string(nums[0]);
    return res;
}