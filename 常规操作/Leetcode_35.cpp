#include "iostream"
#include "vector"
using namespace std;

int searchInsert_LJ(vector<int> &nums, int target)
{
    if (!nums.size())
        return 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (target <= nums[i])
            return i;
    }
    return nums.size();
}

int BSearch(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int searchInsert(vector<int> &nums, int target)
{

    if (!nums.size())
        return 0;
    if (target <= nums[0])
        return 0;
    if (target > nums[nums.size() - 1])
        return nums.size();
    int poss = BSearch(nums, target);
    return poss;
}