#include "iostream"
#include "vector"
using namespace std;

int findMin(vector<int> &nums)
{
    if(!nums.size())
        return -1;
    int low = 0, high = nums.size() - 1;
    while(low < high)
    {
        int mid = (high - low) / 2 + low;
        if(nums[mid]>nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}

