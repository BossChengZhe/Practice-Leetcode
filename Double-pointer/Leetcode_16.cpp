#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    if(nums.size() < 3)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res(0, vector<int>(3));
    res.push_back({nums[0], nums[1], nums[2]});
    int distance = abs(nums[0] + nums[1] + nums[2] - target);
    int temp = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < nums.size()-2; i++)
    {
        int j = i + 1, p = nums.size() - 1;
        while(j < p)
        {
            if(distance > abs(nums[i] + nums[j] + nums[p] - target))
            {
                temp = nums[i] + nums[j] + nums[p];
                distance = abs(nums[i] + nums[j] + nums[p] - target);
            }
            if(nums[i] + nums[j] + nums[p] < target)
                j++;
            else if(nums[i] + nums[j] + nums[p] > target)
                p--;
            else
                return temp;
        }
    }
    return temp;
}

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int res = threeSumClosest(nums, 1);
    cout << res << endl;
    return 0;
}   