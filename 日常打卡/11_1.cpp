#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool find(int target, vector<int> &nums)
{
    int low = 0, high = nums.size()-1;
    while(low<high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid]==target)
            return true;
        else if(nums[mid]<target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return nums[low] == target;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.size()==0 || nums2.size()==0)
        return {};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    for(int i = 0; i < nums1.size(); i++)
    {
        if(i && nums1[i]==nums1[i-1])
            continue;
        if(find(nums1[i], nums2))
            res.push_back(nums1[i]);
    }
    return res;
}