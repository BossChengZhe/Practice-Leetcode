#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

bool canJump(vector<int> &nums)
{
    int max_pos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i <= max_pos)
        {
            max_pos = max(max_pos, i + nums[i]);
            if (max_pos >= nums.size() - 1)
                return true;
        }
    }
    return false;
}