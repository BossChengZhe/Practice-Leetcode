#include "iostream"
#include "vector"
using namespace std;

int search(vector<int> &nums, int target)
{
    if(nums.size()==1)
        return target == nums[0] ? 1 : -1;
    int low = 0, high = nums.size() - 1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>=nums[0])
        {
            // 说明左边是有序的
            if(target<=nums[mid]&&target>=nums[0])
                high = mid-1;
            else
                low = mid+1;
        }
        else
        {
            // 右边应该是有序的
            if(target>=nums[mid]&&target<=nums[nums.size()-1])
                low = mid+1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    search(nums, 2);
    return 0;
}