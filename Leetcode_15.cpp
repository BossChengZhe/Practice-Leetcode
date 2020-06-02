#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    if (nums.size() < 3)
        return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0 || i > nums.size() - 3)
            break;
        if (i && nums[i - 1] == nums[i])
            continue;
        int j = i + 1, p = nums.size() - 1;
        int temp;
        while (j < p)
        {
            if (nums[j] + nums[p] + nums[i] > 0)
            {
                temp = nums[p];
                while (temp == nums[p] && p != 0)
                    p--;
            }
            else if (nums[j] + nums[p] + nums[i] < 0)
            {
                temp = nums[j];
                while (temp == nums[j] && j != nums.size()-1)
                    j++;
            }
            else
            {
                res.push_back({nums[i], nums[j], nums[p]});
                temp = nums[p];
                while (temp == nums[p] && p != 0)
                    p--;
                temp = nums[j];
                while (temp == nums[j] && j != nums.size()-1)
                    j++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    threeSum(nums);
    return 0;
}