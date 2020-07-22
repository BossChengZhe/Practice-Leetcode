#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

int jump(vector<int> &nums)
{
    int maxpos = 0, end = 0, res = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        maxpos = max(maxpos, i + nums[i]);
        if (i == end)
        {
            end = maxpos;
            res++;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {2, 3, 5, 1, 1, 1, 1, 10, 1, 1, 4};
    jump(nums);
    return 0;
}