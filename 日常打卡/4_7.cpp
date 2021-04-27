#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int low = 0, high = len - 1;
        if (high < 0)
            return false;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid])
            {
                low++;
                continue;
            }
            else if (nums[mid] > nums[0])
            // 左边有序
            {
                if (target < nums[mid] && target >= nums[0])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else 
            {
                if(target > nums[mid] && target <= nums[len-1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return nums[low] == target;
    }
};