#include "iostream"
#include "vector"
using namespace std;

int findMin(vector<int> &nums)
{
    if (!nums.size())
        return -1;
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high--;
    }
    return nums[low];
}