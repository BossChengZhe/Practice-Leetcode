#include "algorithm"
#include "cmath"
#include "iostream"
#include "vector"
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    if (nums.size() < 3)
        return -1;
    if (nums.size() == 3)
        return nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    int temp = 0;
    int distance = abs(target - (nums[0] + nums[1] + nums[2]));
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            if(distance > abs(target - (nums[i] + nums[j] + nums[k])))
            {
                temp = nums[i] + nums[j] + nums[k];
                distance = abs(target - (nums[i] + nums[j] + nums[k]));
            }
            if(target > (nums[i] + nums[j] + nums[k]))
                j++;
            else if(target < (nums[i] + nums[j] + nums[k]))
                k--;
            else
                return nums[i] + nums[j] + nums[k];
        }
    }
    return temp;
}