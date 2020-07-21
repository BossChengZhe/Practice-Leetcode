#include "iostream"
#include "vector"
using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    if (high < 0)
        return false;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
            return true;
        if (nums[mid] == nums[low])
            low++;
        if (nums[0] < nums[mid])
        {
            if (target < nums[mid] && target >= nums[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target > nums[mid] && target <= nums[nums.size() - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return nums[low] == target;
}