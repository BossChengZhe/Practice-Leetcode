#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int find(vector<int> &nums_list, int goal)
{
    int low = 0, high = nums_list.size() - 1;
    while(low<high)
    {
        int mid = low + (high - low) / 2;
        if(nums_list[mid]>= goal)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> nums_list = nums;
    sort(nums_list.begin(), nums_list.end());
    vector<int> res;
    for(int i = 0; i < nums.size(); i++)
    {
        res.push_back(find(nums_list, nums[i]));
    }
    return res;
}