#include "iostream"
#include "vector"
using namespace std;

int findMagicIndex(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while(low<high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        if(nums[mid]>=mid)
            high = mid;
        else
            low = mid + 1;
    }
    return nums[low] == low ? low : -1;
}
